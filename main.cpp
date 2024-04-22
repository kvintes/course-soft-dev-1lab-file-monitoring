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

    QString currentDir = QDir::currentPath();
    QString currentFilePathProject = currentDir.section("/", 0, -2);//получили папку, где лежит проект
    QString doc_txt = currentFilePathProject+"/course-soft-dev-1lab-file-monitoring/testFiles/test.docx";
    QString jpg_txt = currentFilePathProject+"/course-soft-dev-1lab-file-monitoring/testFiles/test.jpg ";
    instance.addTrackedFile(doc_txt);

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

