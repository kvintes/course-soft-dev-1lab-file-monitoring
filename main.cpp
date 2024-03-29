#include <QCoreApplication>
#include <TestFile.h>
#include <testLogerConsole.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //TestFile test;
    //test.testEmpty();

    TestLogerConsole testLogerConsole;
    testLogerConsole.testOutputMessage();
    return a.exec();
}
