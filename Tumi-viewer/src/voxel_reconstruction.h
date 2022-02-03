/*
Surface Reconstruction for any OS1 LiDAR based on voxel downsampling of a point cloud
Author: Carlos Huapaya and Pierre Perez
*/

//Input: Non-overlapped point cloud and its resulting surface reconstruction arrays
//Output: Surface reconstruction of the given point cloud based on the voxel downsampling algorithm (DXF format)

///NOTES:
//The size of the voxels has to be a user input (for now).
//There is a correspondence between the size of the voxels and the form of the scanned scene.
//The greater the voxels, the more information loss of the scene and so the less number of triangles (lighter DXF file)

#ifndef VOXEL_RECONST_H
#define VOXEL_RECONST_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <helper_cuda.h>
#include <helper_functions.h>
#include <time.h>
#include "overlap.h"

#define LEAF_SIZE 800.0f

double* voxel_downsampling(double* h_input_cloud, double* d_input_cloud, int num_points, double* h_leaf_size, int** h_idx_points, int** h_idx_voxels, int** h_pos_out, int** h_repeat, int* num_points_out);
int* generate_surface_reconstruction(int* h_surface, int* h_idx_points, int* h_pos_out, int* h_repeat, int num_points_out, int num_points, int num_triangles, int* num_triangles_out);

int Voxel_Reconstruction(double* Point_Cloud, double* downsampled_cloud, int* downsampled_surface, int* num_points_out, int* num_triangles_out)
{
	/////////////////////////////////////////////////////////
	/****************OVERLAPPING ELIMINATION*****************/
	/////////////////////////////////////////////////////////
    
    unsigned int *T,n_triangles_real_data;
    T=(unsigned int*)malloc(n_total_triangles * 3 *sizeof(unsigned int));
    /*****************************************************/
    /***********Obtenemos la malla triangular*************/
    /*****************************************************/
    //Tambien evaluamos tiempo
    clock_t startCPU;
	clock_t finishCPU;
	printf("\n-----------Overlap Elimination-----------\n\n");
	startCPU = clock();
    Generate_surface(Point_Cloud,T,&n_triangles_real_data);
	finishCPU = clock();
	printf("CPU: %fms\n", (double)(finishCPU - startCPU) / 1000);/// CLK_TCK);
	printf("Number of points: %d\n",(int)n_total_points);
	printf("Number of triangles: %d\n",(int)n_triangles_real_data);
	
	// //Creamos el archivo csv
    // archivo = fopen("MinaTriangleMesh.csv", "w+");
    // fprintf(archivo, "V1, V2, V3\n");
    // for (unsigned int i=0; i < n_triangles_real_data; i++) {
    //     fprintf(archivo,"%d, %d, %d\n", T[i*3+0], T[i * 3 + 1], T[i * 3 + 2]);
    // }
    // fclose(archivo);

    /////////////////////////////////////////////////////////
	/********************************************************/
	/////////////////////////////////////////////////////////

	// const char sphere_name[] = "../data/point_cloud.csv";//path of the input cloud
	// const char surface_name[] = "../data/surface.csv";//path of the input connections for surface reconstruction
	// const char downsampled_cloud_name[] = "../data/downsamp_cloud.csv";//path of downsampled point cloud
	// const char downsampled_surf_name[] = "../data/downsamp_surf.csv";
	// const char output_surface_name[] = "../data/surface_reconstruction.dxf";//path for output surface reconstruction
	int num_points = (int)n_total_points, num_triangles = (int)n_triangles_real_data;//initialize the number of points and triangles
	// int num_points_out = 0, num_triangles_out = 0;//reduced number of points and triangles
	FILE* document;
	//cudaError_t err, cudaStatus;
	clock_t start, end;
	long double time;

	//------------------------------------------
	//-----------Read the point cloud-----------
	//------------------------------------------
	// double* h_sphere_pc = read_point_cloud(sphere_name, &num_points);
	// if (h_sphere_pc == NULL) return -1;//check if there was any errors
	// printf("Number of points read: %d\n", num_points);

	// Copy out the point cloud
	double* h_sphere_pc = Point_Cloud;

	//allocate memory for the point cloud in the GPU
	double* d_sphere_pc;
	size_t bytes_sphere = (size_t)3 * (size_t)num_points * sizeof(double);
	checkCudaErrors(cudaMalloc(&d_sphere_pc, bytes_sphere));

	//transfer the point cloud from the CPU to GPU
	checkCudaErrors(cudaMemcpy(d_sphere_pc, h_sphere_pc, bytes_sphere, cudaMemcpyHostToDevice));

	//------------------------------------------
	//-------------Read the surface-------------
	//------------------------------------------
	// int* h_surface = read_surface(surface_name, &num_triangles);
	// if (h_surface == NULL) return -1;//check if there was any errors
	// printf("Number of triangles read: %d\n", num_triangles);

	// Copy out the surface connections
	int* h_surface = (int*)malloc((size_t)num_triangles * (size_t)3 * sizeof(int));
	for(int i=0;i<num_triangles*3;i++) h_surface[i] = (int)T[i];

	int* h_surface_new = (int*)malloc((size_t)num_triangles * (size_t)3 * sizeof(int));
	// printf("Size of h_surface: %d\n", sizeof(h_surface) / sizeof(int));

	//------------------------------------------
	//-----Create the voxel grid structure------
	//------------------------------------------
	printf("\n-----------Voxel Structure-----------\n");
	double h_leaf_size[3] = { LEAF_SIZE, LEAF_SIZE, LEAF_SIZE };// size of voxel
	int* h_idx_points = nullptr, * h_idx_voxels = nullptr, * h_pos_out = nullptr, * h_repeat = nullptr;

	// generate the voxel grid structure
	start = clock();
	downsampled_cloud = voxel_downsampling(h_sphere_pc, d_sphere_pc, num_points, h_leaf_size, &h_idx_points, &h_idx_voxels, &h_pos_out, &h_repeat, num_points_out);
	end = clock();
	time = (double)(end - start) / (double)(CLOCKS_PER_SEC) * 1e3;
	printf("Elapsed time voxel structure: %.4lf ms\n", (double)time);

	//------------------------------------------
	//----Compute the surface reconstruction----
	//------------------------------------------
	printf("\n---------Surface Reconstruction---------\n");
	start = clock();
	downsampled_surface = generate_surface_reconstruction(h_surface, h_idx_points, h_pos_out, h_repeat, *num_points_out, num_points, num_triangles, num_triangles_out);
	end = clock();
	time = (double)(end - start) / (double)(CLOCKS_PER_SEC) * 1e3;
	printf("Elapsed time surface reconstruction: %.4lf ms\n", (double)time);

	free(h_idx_points), free(h_idx_voxels), free(h_pos_out), free(h_repeat);
	free(h_sphere_pc), free(h_surface);
	free(T);

	return 0;
}

#endif