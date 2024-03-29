#include "LogerConsole.h"
#include <QTextStream>

void LogerConsole::outputMessage(QString message) {
    QTextStream out(stdout);
    out << message << endl;
}
