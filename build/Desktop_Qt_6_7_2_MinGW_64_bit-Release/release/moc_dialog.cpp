/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../dialog.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDialogENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDialogENDCLASS = QtMocHelpers::stringData(
    "Dialog",
    "do_clipboardDataChanged",
    "",
    "do_trayIconActivated",
    "QSystemTrayIcon::ActivationReason",
    "reason",
    "do_toggleWindow",
    "do_showMainTableMenu",
    "do_showSubTableMenu",
    "do_searchData",
    "searchText",
    "on_listWidget_itemDoubleClicked",
    "QListWidgetItem*",
    "item",
    "on_actClearDB_triggered",
    "on_actExit_triggered",
    "on_actReloadDB_triggered",
    "on_actCreateGroup_triggered",
    "on_actMove2Grop_triggered",
    "on_actRemoveItem_triggered",
    "on_actRemoveGroup_triggered",
    "on_actShortCut_triggered",
    "on_actHelp_triggered"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDialogENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  110,    2, 0x08,    1 /* Private */,
       3,    1,  111,    2, 0x08,    2 /* Private */,
       6,    0,  114,    2, 0x08,    4 /* Private */,
       7,    0,  115,    2, 0x08,    5 /* Private */,
       8,    0,  116,    2, 0x08,    6 /* Private */,
       9,    1,  117,    2, 0x08,    7 /* Private */,
      11,    1,  120,    2, 0x08,    9 /* Private */,
      14,    0,  123,    2, 0x08,   11 /* Private */,
      15,    0,  124,    2, 0x08,   12 /* Private */,
      16,    0,  125,    2, 0x08,   13 /* Private */,
      17,    0,  126,    2, 0x08,   14 /* Private */,
      18,    0,  127,    2, 0x08,   15 /* Private */,
      19,    0,  128,    2, 0x08,   16 /* Private */,
      20,    0,  129,    2, 0x08,   17 /* Private */,
      21,    0,  130,    2, 0x08,   18 /* Private */,
      22,    0,  131,    2, 0x08,   19 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
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

Q_CONSTINIT const QMetaObject Dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Dialog, std::true_type>,
        // method 'do_clipboardDataChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_trayIconActivated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QSystemTrayIcon::ActivationReason, std::false_type>,
        // method 'do_toggleWindow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_showMainTableMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_showSubTableMenu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'do_searchData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_listWidget_itemDoubleClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>,
        // method 'on_actClearDB_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actExit_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actReloadDB_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actCreateGroup_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actMove2Grop_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actRemoveItem_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actRemoveGroup_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actShortCut_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_actHelp_triggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->do_clipboardDataChanged(); break;
        case 1: _t->do_trayIconActivated((*reinterpret_cast< std::add_pointer_t<QSystemTrayIcon::ActivationReason>>(_a[1]))); break;
        case 2: _t->do_toggleWindow(); break;
        case 3: _t->do_showMainTableMenu(); break;
        case 4: _t->do_showSubTableMenu(); break;
        case 5: _t->do_searchData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->on_listWidget_itemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 7: _t->on_actClearDB_triggered(); break;
        case 8: _t->on_actExit_triggered(); break;
        case 9: _t->on_actReloadDB_triggered(); break;
        case 10: _t->on_actCreateGroup_triggered(); break;
        case 11: _t->on_actMove2Grop_triggered(); break;
        case 12: _t->on_actRemoveItem_triggered(); break;
        case 13: _t->on_actRemoveGroup_triggered(); break;
        case 14: _t->on_actShortCut_triggered(); break;
        case 15: _t->on_actHelp_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
