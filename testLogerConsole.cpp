#include "testLogerConsole.h"

void TestLogerConsole::testOutputMessage() {
    ILoger* loger = new LogerConsole();
    QString message = "работает тест функции OutputMessage "+QString::number(123)+QString("123");
    loger->outputMessage(message);
    delete loger;
}
