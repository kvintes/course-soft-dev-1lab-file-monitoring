#ifndef ILOGER_H
#define ILOGER_H
#include <QObject>
#include <QString>

class ILoger:public QObject
{
    Q_OBJECT
public:
    ILoger(QObject* parent):QObject(parent){}
    virtual void outputMessage(QString) = 0;
};

#endif // ILOGER_H
