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
    LogerConsole logger(&a);
    FileManager& instance = FileManager::InstanceFileManager(&logger, nullptr);

    QString currentDir = QDir::currentPath();
    QString currentFilePathProject = currentDir.section("/", 0, -2);//получили папку, где лежит проект
    QString doc_txt = currentFilePathProject+"/course-soft-dev-1lab-file-monitoring/testFiles/test.docx";
    QString jpg_txt = currentFilePathProject+"/course-soft-dev-1lab-file-monitoring/testFiles/t.jpg";
    instance.addTrackedFile(doc_txt);
    instance.addTrackedFile(jpg_txt);


    logger.outputMessage(instance.getInfo());
    instance.setLoger(&logger);

    QTimer timer(&a);
    timer.start(5000);

    QObject::connect(&a, &QCoreApplication::destroyed, [&]() {
        timer.stop();
    });

    int i = 0;
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        std::cout<<"working "<<++i<<std::endl;
        instance.checkFilesStates();
    });
    return a.exec();
}

