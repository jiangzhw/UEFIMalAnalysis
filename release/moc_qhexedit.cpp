/****************************************************************************
** Meta object code from reading C++ file 'qhexedit.h'
**
** Created: Sun Jul 17 16:01:19 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qhexedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhexedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QHexEdit[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       5,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   10,    9,    9, 0x05,
      50,   45,    9,    9, 0x05,
      74,    9,    9,    9, 0x05,
      94,   88,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     134,  121,    9,    9, 0x0a,
     167,  155,    9,    9, 0x0a,
     198,  188,    9,    9, 0x0a,
     222,  217,    9,    9, 0x0a,

 // properties: name, type, flags
     255,  244, 0x0c095103,
     264,  260, 0x02095103,
     285,  278, 0x43095103,
     302,  278, 0x43095103,
     325,  320, 0x01095103,

       0        // eod
};

static const char qt_meta_stringdata_QHexEdit[] = {
    "QHexEdit\0\0address\0currentAddressChanged(int)\0"
    "size\0currentSizeChanged(int)\0dataChanged()\0"
    "state\0overwriteModeChanged(bool)\0"
    "addressWidth\0setAddressWidth(int)\0"
    "addressArea\0setAddressArea(bool)\0"
    "asciiArea\0setAsciiArea(bool)\0mode\0"
    "setHighlighting(bool)\0QByteArray\0data\0"
    "int\0addressOffset\0QColor\0addressAreaColor\0"
    "highlightingColor\0bool\0overwriteMode\0"
};

const QMetaObject QHexEdit::staticMetaObject = {
    { &QScrollArea::staticMetaObject, qt_meta_stringdata_QHexEdit,
      qt_meta_data_QHexEdit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QHexEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QHexEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QHexEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QHexEdit))
        return static_cast<void*>(const_cast< QHexEdit*>(this));
    return QScrollArea::qt_metacast(_clname);
}

int QHexEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollArea::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: currentAddressChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: currentSizeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: dataChanged(); break;
        case 3: overwriteModeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: setAddressWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: setAddressArea((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: setAsciiArea((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: setHighlighting((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QByteArray*>(_v) = data(); break;
        case 1: *reinterpret_cast< int*>(_v) = addressOffset(); break;
        case 2: *reinterpret_cast< QColor*>(_v) = addressAreaColor(); break;
        case 3: *reinterpret_cast< QColor*>(_v) = highlightingColor(); break;
        case 4: *reinterpret_cast< bool*>(_v) = overwriteMode(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setData(*reinterpret_cast< QByteArray*>(_v)); break;
        case 1: setAddressOffset(*reinterpret_cast< int*>(_v)); break;
        case 2: setAddressAreaColor(*reinterpret_cast< QColor*>(_v)); break;
        case 3: setHighlightingColor(*reinterpret_cast< QColor*>(_v)); break;
        case 4: setOverwriteMode(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QHexEdit::currentAddressChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QHexEdit::currentSizeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QHexEdit::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QHexEdit::overwriteModeChanged(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
