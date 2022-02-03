/****************************************************************************
** Meta object code from reading C++ file 'pclviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/pclviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pclviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PCLViewer_t {
    QByteArrayData data[11];
    char stringdata0[261];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PCLViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PCLViewer_t qt_meta_stringdata_PCLViewer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PCLViewer"
QT_MOC_LITERAL(1, 10, 28), // "on_pushButton_yellow_pressed"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 27), // "on_pushButton_black_pressed"
QT_MOC_LITERAL(4, 68, 27), // "on_pushButton_white_pressed"
QT_MOC_LITERAL(5, 96, 25), // "on_pushButton_red_pressed"
QT_MOC_LITERAL(6, 122, 26), // "on_pushButton_blue_pressed"
QT_MOC_LITERAL(7, 149, 42), // "on_horizontalSlider_PointSize..."
QT_MOC_LITERAL(8, 192, 5), // "value"
QT_MOC_LITERAL(9, 198, 32), // "on_pushButton_PointCloud_pressed"
QT_MOC_LITERAL(10, 231, 29) // "on_pushButton_Surface_pressed"

    },
    "PCLViewer\0on_pushButton_yellow_pressed\0"
    "\0on_pushButton_black_pressed\0"
    "on_pushButton_white_pressed\0"
    "on_pushButton_red_pressed\0"
    "on_pushButton_blue_pressed\0"
    "on_horizontalSlider_PointSize_valueChanged\0"
    "value\0on_pushButton_PointCloud_pressed\0"
    "on_pushButton_Surface_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PCLViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    1,   59,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PCLViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PCLViewer *_t = static_cast<PCLViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_yellow_pressed(); break;
        case 1: _t->on_pushButton_black_pressed(); break;
        case 2: _t->on_pushButton_white_pressed(); break;
        case 3: _t->on_pushButton_red_pressed(); break;
        case 4: _t->on_pushButton_blue_pressed(); break;
        case 5: _t->on_horizontalSlider_PointSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_pushButton_PointCloud_pressed(); break;
        case 7: _t->on_pushButton_Surface_pressed(); break;
        default: ;
        }
    }
}

const QMetaObject PCLViewer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PCLViewer.data,
      qt_meta_data_PCLViewer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PCLViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PCLViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PCLViewer.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PCLViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
