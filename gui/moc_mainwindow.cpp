/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Jan 6 20:48:34 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      39,   11,   11,   11, 0x0a,
      54,   11,   11,   11, 0x0a,
      73,   11,   11,   11, 0x0a,
      97,   11,   11,   11, 0x0a,
     113,   11,   11,   11, 0x08,
     145,  139,   11,   11, 0x08,
     178,   11,   11,   11, 0x08,
     202,   11,   11,   11, 0x08,
     230,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0fileLayoutChanged(QString)\0"
    "debug(QString)\0delButtonClicked()\0"
    "setQueryString(QString)\0search(QString)\0"
    "on_pushButton_2_clicked()\0index\0"
    "on_tabWidget_currentChanged(int)\0"
    "on_pushButton_clicked()\0"
    "on_lineEdit_returnPressed()\0"
    "on_textBrowser_textChanged()\0"
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
        case 0: fileLayoutChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: debug((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: delButtonClicked(); break;
        case 3: setQueryString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: search((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: on_pushButton_2_clicked(); break;
        case 6: on_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_pushButton_clicked(); break;
        case 8: on_lineEdit_returnPressed(); break;
        case 9: on_textBrowser_textChanged(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE