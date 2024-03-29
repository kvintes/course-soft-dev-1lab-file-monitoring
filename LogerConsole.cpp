#include "LogerConsole.h"

void LogerConsole::outputMessage(QString message) {
    std::cout<<message.toStdString()<<std::endl;
}
