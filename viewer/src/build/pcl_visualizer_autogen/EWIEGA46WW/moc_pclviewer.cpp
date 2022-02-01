/****************************************************************************
** Meta object code from reading C++ file 'pclviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../pclviewer.h"
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
    QByteArrayData data[16];
    char stringdata0[395];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PCLViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PCLViewer_t qt_meta_stringdata_PCLViewer = {
    {
QT_MOC_LITERAL(0, 0, 9), // "PCLViewer"
QT_MOC_LITERAL(1, 10, 17), // "RGBsliderReleased"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 19), // "pSliderValueChanged"
QT_MOC_LITERAL(4, 49, 5), // "value"
QT_MOC_LITERAL(5, 55, 21), // "redSliderValueChanged"
QT_MOC_LITERAL(6, 77, 23), // "greenSliderValueChanged"
QT_MOC_LITERAL(7, 101, 22), // "blueSliderValueChanged"
QT_MOC_LITERAL(8, 124, 28), // "on_pushButton_random_pressed"
QT_MOC_LITERAL(9, 153, 27), // "on_pushButton_clear_pressed"
QT_MOC_LITERAL(10, 181, 25), // "on_pushButton_add_pressed"
QT_MOC_LITERAL(11, 207, 37), // "on_pushButton_blackbackground..."
QT_MOC_LITERAL(12, 245, 38), // "on_pushButton_yellowbackgroun..."
QT_MOC_LITERAL(13, 284, 35), // "on_pushButton_redbackground_p..."
QT_MOC_LITERAL(14, 320, 37), // "on_pushButton_whitebackground..."
QT_MOC_LITERAL(15, 358, 36) // "on_pushButton_bluebackground_..."

    },
    "PCLViewer\0RGBsliderReleased\0\0"
    "pSliderValueChanged\0value\0"
    "redSliderValueChanged\0greenSliderValueChanged\0"
    "blueSliderValueChanged\0"
    "on_pushButton_random_pressed\0"
    "on_pushButton_clear_pressed\0"
    "on_pushButton_add_pressed\0"
    "on_pushButton_blackbackground_pressed\0"
    "on_pushButton_yellowbackground_pressed\0"
    "on_pushButton_redbackground_pressed\0"
    "on_pushButton_whitebackground_pressed\0"
    "on_pushButton_bluebackground_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PCLViewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x0a /* Public */,
       3,    1,   80,    2, 0x0a /* Public */,
       5,    1,   83,    2, 0x0a /* Public */,
       6,    1,   86,    2, 0x0a /* Public */,
       7,    1,   89,    2, 0x0a /* Public */,
       8,    0,   92,    2, 0x08 /* Private */,
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 0: _t->RGBsliderReleased(); break;
        case 1: _t->pSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->redSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->greenSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->blueSliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_random_pressed(); break;
        case 6: _t->on_pushButton_clear_pressed(); break;
        case 7: _t->on_pushButton_add_pressed(); break;
        case 8: _t->on_pushButton_blackbackground_pressed(); break;
        case 9: _t->on_pushButton_yellowbackground_pressed(); break;
        case 10: _t->on_pushButton_redbackground_pressed(); break;
        case 11: _t->on_pushButton_whitebackground_pressed(); break;
        case 12: _t->on_pushButton_bluebackground_pressed(); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
