#ifndef ILOGER_H
#define ILOGER_H
#include <QString>

class ILoger
{
public:
    virtual outputMessage(QString) = 0;
};

#endif // ILOGER_H
