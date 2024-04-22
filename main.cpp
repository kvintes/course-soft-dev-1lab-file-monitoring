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
    //test commit
    QCoreApplication a(argc, argv);
    FileManager& instance = FileManager::InstanceFileManager();
    return a.exec();
}

