#include <QCoreApplication>

#include <FileManager.h>
#include <LogerConsole.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <QTimer>
#include <QDir>

int main(int argc, char *argv[])
{
    //проверка на merge
    QCoreApplication a(argc, argv);
    FileManager fileManager;
    return a.exec();
}

