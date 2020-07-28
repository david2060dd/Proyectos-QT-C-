/****************************************************************************
** Meta object code from reading C++ file 'principal.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../principal.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'principal.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Principal_t {
    QByteArrayData data[10];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Principal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Principal_t qt_meta_stringdata_Principal = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Principal"
QT_MOC_LITERAL(1, 10, 13), // "mostrarPrecio"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 15), // "agregarProducto"
QT_MOC_LITERAL(4, 41, 13), // "validarCedula"
QT_MOC_LITERAL(5, 55, 7), // "factura"
QT_MOC_LITERAL(6, 63, 3), // "dat"
QT_MOC_LITERAL(7, 67, 7), // "limpiar"
QT_MOC_LITERAL(8, 75, 36), // "on_actionAgregar_productos_tr..."
QT_MOC_LITERAL(9, 112, 28) // "on_actionAcerca_de_triggered"

    },
    "Principal\0mostrarPrecio\0\0agregarProducto\0"
    "validarCedula\0factura\0dat\0limpiar\0"
    "on_actionAgregar_productos_triggered\0"
    "on_actionAcerca_de_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Principal[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x0a /* Public */,
       3,    0,   57,    2, 0x0a /* Public */,
       4,    0,   58,    2, 0x0a /* Public */,
       5,    0,   59,    2, 0x0a /* Public */,
       6,    0,   60,    2, 0x0a /* Public */,
       7,    0,   61,    2, 0x0a /* Public */,
       8,    0,   62,    2, 0x08 /* Private */,
       9,    0,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Principal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Principal *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mostrarPrecio((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->agregarProducto(); break;
        case 2: _t->validarCedula(); break;
        case 3: _t->factura(); break;
        case 4: _t->dat(); break;
        case 5: _t->limpiar(); break;
        case 6: _t->on_actionAgregar_productos_triggered(); break;
        case 7: _t->on_actionAcerca_de_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Principal::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_Principal.data,
    qt_meta_data_Principal,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Principal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Principal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Principal.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Principal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
