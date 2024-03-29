#include "testLogerConsole.h"

void TestLogerConsole::testOutputMessage() {
    ILoger* loger = new LogerConsole();
    QString message = "работает тест функции OutputMessage";
    loger->outputMessage(message);
    delete loger;
}
