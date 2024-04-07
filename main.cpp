#include <QCoreApplication>
#include <TestFile.h>
#include <testLogerConsole.h>

#include <FileManager.h>
#include <LogerConsole.h>
#include <iostream>
#include <thread>
#include <chrono>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //TestFile test;
    //test.testEmpty();

    // TestLogerConsole testLogerConsole;
    // testLogerConsole.testOutputMessage();
    // QString filePaths = "fewgerh/fewgerh/wegrhte";
    // QString sep = "/";
    // FileManager test(filePaths, sep);

    //ILoger * testLoger = new LogerConsole;
    // testLoger->outputMessage(test.getInfo());

    QString filePaths = "C:/Users/Acer/Downloads/test.docxpppC:/Users/Acer/Downloads/IMG_test.PNG";
    FileManager fileManager(filePaths, "ppp");
    LogerConsole logger;
    fileManager.setLoger(&logger);
    int i = 0;
    while (true) {
        fileManager.checkStates();
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        std::cout<<"working "<<++i<<std::endl;
    }

    return a.exec();
}
