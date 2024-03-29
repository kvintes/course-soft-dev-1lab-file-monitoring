#include <QCoreApplication>
#include <TestFile.h>
#include <testLogerConsole.h>

#include <FileManager.h>
#include <LogerConsole.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //TestFile test;
    //test.testEmpty();

    // TestLogerConsole testLogerConsole;
    // testLogerConsole.testOutputMessage();
    QString filePaths = "fewgerh/fewgerh/wegrhte";
    QString sep = "/";
    FileManager test(filePaths, sep);

    ILoger * testLoger = new LogerConsole;
    testLoger->outputMessage(test.getInfo());

    return a.exec();
}
