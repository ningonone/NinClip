/****************************************************************************
** Meta object code from reading C++ file 'qhotkey.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../lib/QHotkey/QHotkey/qhotkey.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qhotkey.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSQHotkeyENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSQHotkeyENDCLASS = QtMocHelpers::stringData(
    "QHotkey",
    "activated",
    "",
    "released",
    "registeredChanged",
    "registered",
    "setRegistered",
    "setShortcut",
    "QKeySequence",
    "shortcut",
    "autoRegister",
    "Qt::Key",
    "keyCode",
    "Qt::KeyboardModifiers",
    "modifiers",
    "resetShortcut",
    "setNativeShortcut",
    "NativeShortcut",
    "nativeShortcut"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQHotkeyENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       2,  117, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x06,    3 /* Public */,
       3,    0,   81,    2, 0x06,    4 /* Public */,
       4,    1,   82,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   85,    2, 0x0a,    7 /* Public */,
       7,    2,   88,    2, 0x0a,    9 /* Public */,
       7,    1,   93,    2, 0x2a,   12 /* Public | MethodCloned */,
       7,    3,   96,    2, 0x0a,   14 /* Public */,
       7,    2,  103,    2, 0x2a,   18 /* Public | MethodCloned */,
      15,    0,  108,    2, 0x0a,   21 /* Public */,
      16,    2,  109,    2, 0x0a,   22 /* Public */,
      16,    1,  114,    2, 0x2a,   25 /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,

 // slots: parameters
    QMetaType::Bool, QMetaType::Bool,    5,
    QMetaType::Bool, 0x80000000 | 8, QMetaType::Bool,    9,   10,
    QMetaType::Bool, 0x80000000 | 8,    9,
    QMetaType::Bool, 0x80000000 | 11, 0x80000000 | 13, QMetaType::Bool,   12,   14,   10,
    QMetaType::Bool, 0x80000000 | 11, 0x80000000 | 13,   12,   14,
    QMetaType::Bool,
    QMetaType::Bool, 0x80000000 | 17, QMetaType::Bool,   18,   10,
    QMetaType::Bool, 0x80000000 | 17,   18,

 // properties: name, type, flags
       5, QMetaType::Bool, 0x00015103, uint(2), 0,
       9, 0x80000000 | 8, 0x0001510f, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QHotkey::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSQHotkeyENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQHotkeyENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQHotkeyENDCLASS_t,
        // property 'registered'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'shortcut'
        QtPrivate::TypeAndForceComplete<QKeySequence, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QHotkey, std::true_type>,
        // method 'activated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'released'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'registeredChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setRegistered'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setShortcut'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QKeySequence &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setShortcut'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QKeySequence &, std::false_type>,
        // method 'setShortcut'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<Qt::KeyboardModifiers, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setShortcut'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<Qt::Key, std::false_type>,
        QtPrivate::TypeAndForceComplete<Qt::KeyboardModifiers, std::false_type>,
        // method 'resetShortcut'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setNativeShortcut'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<NativeShortcut, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'setNativeShortcut'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<NativeShortcut, std::false_type>
    >,
    nullptr
} };

void QHotkey::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QHotkey *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->activated(QPrivateSignal()); break;
        case 1: _t->released(QPrivateSignal()); break;
        case 2: _t->registeredChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: { bool _r = _t->setRegistered((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->setShortcut((*reinterpret_cast< std::add_pointer_t<QKeySequence>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->setShortcut((*reinterpret_cast< std::add_pointer_t<QKeySequence>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->setShortcut((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->setShortcut((*reinterpret_cast< std::add_pointer_t<Qt::Key>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Qt::KeyboardModifiers>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: { bool _r = _t->resetShortcut();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->setNativeShortcut((*reinterpret_cast< std::add_pointer_t<NativeShortcut>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { bool _r = _t->setNativeShortcut((*reinterpret_cast< std::add_pointer_t<NativeShortcut>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QHotkey::*)(QPrivateSignal);
            if (_t _q_method = &QHotkey::activated; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QHotkey::*)(QPrivateSignal);
            if (_t _q_method = &QHotkey::released; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QHotkey::*)(bool );
            if (_t _q_method = &QHotkey::registeredChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QHotkey *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->isRegistered(); break;
        case 1: *reinterpret_cast< QKeySequence*>(_v) = _t->shortcut(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QHotkey *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRegistered(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setShortcut(*reinterpret_cast< QKeySequence*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
        auto *_t = static_cast<QHotkey *>(_o);
        (void)_t;
        switch (_id) {
        case 1: _t->resetShortcut(); break;
        default: break;
        }
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *QHotkey::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QHotkey::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQHotkeyENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QHotkey::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QHotkey::activated(QPrivateSignal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QHotkey::released(QPrivateSignal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QHotkey::registeredChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
