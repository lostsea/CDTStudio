#ifndef CDTPBCDDIFFINTERFACE_H
#define CDTPBCDDIFFINTERFACE_H

#include <QtCore>
#include <QtPlugin>
#include <QProgressBar>
#include <QLabel>

class CDTPBCDDiffInterface:public QObject
{
    Q_OBJECT
public:
    explicit CDTPBCDDiffInterface(QObject* parent = 0):QObject(parent){}

    virtual QString methodName()const =0;
};

Q_DECLARE_INTERFACE(CDTPBCDDiffInterface,"cn.edu.WHU.CDTStudio.CDTPBCDDiffInterface/1.0")

#endif // CDTPBCDDIFFINTERFACE_H
