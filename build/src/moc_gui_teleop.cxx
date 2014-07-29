/****************************************************************************
** Meta object code from reading C++ file 'gui_teleop.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../src/gui_teleop.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gui_teleop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_sesto_rviz_plugins__GuiTeleop[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      30,   50,   85,   85, 0x0a,
      86,  104,   85,   85, 0x0a,
     110,   85,   85,   85, 0x09,
     120,   85,   85,   85, 0x09,
     138,   85,   85,   85, 0x09,
     157,   85,   85,   85, 0x09,
     173,   85,   85,   85, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_sesto_rviz_plugins__GuiTeleop[] = {
    "sesto_rviz_plugins::GuiTeleop\0"
    "setVel(float,float)\0"
    "linear_velocity_,angular_velocity_\0\0"
    "setTopic(QString)\0topic\0sendVel()\0"
    "setMaxLinearVel()\0setMaxAngularVel()\0"
    "suppressSpeed()\0updateTopic()\0"
};

void sesto_rviz_plugins::GuiTeleop::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GuiTeleop *_t = static_cast<GuiTeleop *>(_o);
        switch (_id) {
        case 0: _t->setVel((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 1: _t->setTopic((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->sendVel(); break;
        case 3: _t->setMaxLinearVel(); break;
        case 4: _t->setMaxAngularVel(); break;
        case 5: _t->suppressSpeed(); break;
        case 6: _t->updateTopic(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData sesto_rviz_plugins::GuiTeleop::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject sesto_rviz_plugins::GuiTeleop::staticMetaObject = {
    { &rviz::Panel::staticMetaObject, qt_meta_stringdata_sesto_rviz_plugins__GuiTeleop,
      qt_meta_data_sesto_rviz_plugins__GuiTeleop, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &sesto_rviz_plugins::GuiTeleop::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *sesto_rviz_plugins::GuiTeleop::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *sesto_rviz_plugins::GuiTeleop::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_sesto_rviz_plugins__GuiTeleop))
        return static_cast<void*>(const_cast< GuiTeleop*>(this));
    typedef rviz::Panel QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int sesto_rviz_plugins::GuiTeleop::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef rviz::Panel QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
