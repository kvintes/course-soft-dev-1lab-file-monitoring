#ifndef LOGERCONSOLE_H
#define LOGERCONSOLE_H
#include "ILoger.h"

class LogerConsole:public ILoger
{
public:
    LogerConsole(QObject* parent):ILoger(parent){}
    virtual void outputMessage(QString) override;
};

#endif // LOGERCONSOLE_H
