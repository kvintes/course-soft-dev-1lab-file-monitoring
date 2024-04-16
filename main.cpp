#include <QCoreApplication>
#include <TestFile.h>
#include <testLogerConsole.h>

#include <FileManager.h>
#include <LogerConsole.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <QTimer>
#include <QDir>
void tests(){
    TestFile testFile;
    testFile.testEmpty();

    TestLogerConsole testLogerConsole;
    testLogerConsole.testOutputMessage();
    QString filePaths = "fewgerh/fewgerh/wegrhte";
    QString sep = "/";
    FileManager test(filePaths, sep);

    ILoger * testLoger = new LogerConsole(nullptr);
    testLoger->outputMessage(test.getInfo());
    if(testLoger){
        delete testLoger;
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString currentDir = QDir::currentPath();
    QString currentFilePathProject = currentDir.section("/", 0, -2);//получили папку, где лежит проект
    QString filePaths = currentFilePathProject+"/course-soft-dev-1lab-file-monitoring/testFiles/test.docx "
                        + currentFilePathProject+"/course-soft-dev-1lab-file-monitoring/testFiles/test.jpg ";
    QString sep = " ";
    FileManager fileManager(filePaths, sep, &a);

    LogerConsole logger(&a);
    logger.outputMessage(fileManager.getInfo());
    fileManager.setLoger(&logger);

    QTimer timer(&a);
    timer.start(5000);

    QObject::connect(&a, &QCoreApplication::destroyed, [&]() {
        timer.stop();
    });

    int i = 0;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        std::cout<<"working "<<++i<<std::endl;
        fileManager.checkStates();
    });

    return a.exec();
}
// int j = 0;
// while (true) {
//     fileManager.checkStates();
//     std::this_thread::sleep_for(std::chrono::milliseconds(5000));
//     std::cout<<"working j"<<++j<<std::endl;
// }
