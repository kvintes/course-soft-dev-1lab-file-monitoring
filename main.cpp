#include <QCoreApplication>
#include <TestFile.h>
#include <testLogerConsole.h>

#include <FileManager.h>
#include <LogerConsole.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <QTimer>
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

    QString filePaths = "C:/Users/Acer/Downloads/test.docxpppC:/Users/Acer/Downloads/IMG_test.PNG";
    FileManager fileManager(filePaths, "ppp", &a);

    LogerConsole logger(&a);
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



    // int i = 0;
    // while (true) {
    //     fileManager.checkStates();
    //     std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    //     std::cout<<"working "<<++i<<std::endl;
    // }

    return a.exec();
}
