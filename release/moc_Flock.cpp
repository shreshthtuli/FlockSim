/****************************************************************************
** Meta object code from reading C++ file 'Flock.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Starling-Flock-Simulator/Flock.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Flock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Flock_t {
    QByteArrayData data[15];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Flock_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Flock_t qt_meta_stringdata_Flock = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Flock"
QT_MOC_LITERAL(1, 6, 16), // "xRotationChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "angle"
QT_MOC_LITERAL(4, 30, 16), // "yRotationChanged"
QT_MOC_LITERAL(5, 47, 16), // "zRotationChanged"
QT_MOC_LITERAL(6, 64, 7), // "addBoid"
QT_MOC_LITERAL(7, 72, 1), // "x"
QT_MOC_LITERAL(8, 74, 1), // "y"
QT_MOC_LITERAL(9, 76, 1), // "z"
QT_MOC_LITERAL(10, 78, 8), // "strength"
QT_MOC_LITERAL(11, 87, 3), // "adv"
QT_MOC_LITERAL(12, 91, 11), // "sightedness"
QT_MOC_LITERAL(13, 103, 4), // "fova"
QT_MOC_LITERAL(14, 108, 4) // "fovb"

    },
    "Flock\0xRotationChanged\0\0angle\0"
    "yRotationChanged\0zRotationChanged\0"
    "addBoid\0x\0y\0z\0strength\0adv\0sightedness\0"
    "fova\0fovb"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Flock[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       5,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    8,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Int, QMetaType::Int,    7,    8,    9,   10,   11,   12,   13,   14,

       0        // eod
};

void Flock::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Flock *_t = static_cast<Flock *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->xRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->yRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->zRotationChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->addBoid((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4])),(*reinterpret_cast< float(*)>(_a[5])),(*reinterpret_cast< float(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Flock::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Flock::xRotationChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Flock::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Flock::yRotationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Flock::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Flock::zRotationChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Flock::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_Flock.data,
      qt_meta_data_Flock,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Flock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Flock::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Flock.stringdata0))
        return static_cast<void*>(const_cast< Flock*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int Flock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Flock::xRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Flock::yRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Flock::zRotationChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
