#include <QCoreApplication>
#include <TestFile.h>
#include <testLogerConsole.h>
#include <FileManager.h>
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
    return a.exec();
}
