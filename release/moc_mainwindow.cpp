/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Jul 17 16:01:18 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      52,   47,   11,   11, 0x08,
     107,   47,   11,   11, 0x08,
     163,   11,   11,   11, 0x08,
     197,   11,   11,   11, 0x08,
     230,   11,   11,   11, 0x08,
     249,   11,   11,   11, 0x08,
     274,  267,   11,   11, 0x08,
     333,   11,   11,   11, 0x08,
     359,   11,   11,   11, 0x08,
     390,   11,   11,   11, 0x08,
     418,   11,   11,   11, 0x08,
     448,   11,   11,   11, 0x08,
     479,   11,   11,   11, 0x08,
     516,   11,  508,   11, 0x08,
     533,   11,  508,   11, 0x08,
     549,   11,   11,   11, 0x08,
     572,  568,  564,   11, 0x08,
     608,   11,   11,   11, 0x08,
     638,  630,   11,   11, 0x08,
     669,   11,   11,   11, 0x08,
     699,   11,   11,   11, 0x08,
     731,  722,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_DBManCheckBox_stateChanged(int)\0"
    "item\0on_userRulesListWidget_itemActivated(QListWidgetItem*)\0"
    "on_adminRulesListWidget_itemActivated(QListWidgetItem*)\0"
    "show_adminListContextMenu(QPoint)\0"
    "show_userListContextMenu(QPoint)\0"
    "on_delAdminRules()\0on_delUserRules()\0"
    "reason\0"
    "onSystemTrayIconClicked(QSystemTrayIcon::ActivationReason)\0"
    "on_saveRulesBtn_clicked()\0"
    "on_pwdLineEdit_returnPressed()\0"
    "on_addUserRuleBtn_clicked()\0"
    "on_clearUserRuleBtn_clicked()\0"
    "on_clearAdminRuleBtn_clicked()\0"
    "on_addAdminRuleBtn_clicked()\0QString\0"
    "showAdminRules()\0showUserRules()\0"
    "showAllRules()\0int\0A,B\0"
    "ABContainsRelation(QString,QString)\0"
    "on_logInBtn_clicked()\0checked\0"
    "on_DBManCheckBox_toggled(bool)\0"
    "on_startAnalysisBtn_clicked()\0"
    "on_browseBtn_clicked()\0fileName\0"
    "readInRules(QString)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_DBManCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: on_userRulesListWidget_itemActivated((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: on_adminRulesListWidget_itemActivated((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: show_adminListContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 4: show_userListContextMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 5: on_delAdminRules(); break;
        case 6: on_delUserRules(); break;
        case 7: onSystemTrayIconClicked((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 8: on_saveRulesBtn_clicked(); break;
        case 9: on_pwdLineEdit_returnPressed(); break;
        case 10: on_addUserRuleBtn_clicked(); break;
        case 11: on_clearUserRuleBtn_clicked(); break;
        case 12: on_clearAdminRuleBtn_clicked(); break;
        case 13: on_addAdminRuleBtn_clicked(); break;
        case 14: { QString _r = showAdminRules();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 15: { QString _r = showUserRules();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 16: showAllRules(); break;
        case 17: { int _r = ABContainsRelation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 18: on_logInBtn_clicked(); break;
        case 19: on_DBManCheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: on_startAnalysisBtn_clicked(); break;
        case 21: on_browseBtn_clicked(); break;
        case 22: readInRules((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 23;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
