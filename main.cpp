#include <QCoreApplication>
#include <TestFile.h>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestFile test;
    //test.testEmpty();
    return a.exec();
}
