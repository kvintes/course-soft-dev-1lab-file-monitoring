#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QObject>
#include <QString>
#include <QFileInfo>

#include "ILoger.h"
#include <iostream>
#include <QDebug>
#include <vector>

class FileManager:public QObject
{
    Q_OBJECT
private:
    class File
    {
        private:
            QString filePath;
            bool isExists;
            int fileSize;
        public:
            File();
            File(const QString &filePath);
            QString getPath();
            bool getExistsStatus();
            int getSize();

            QString setPath(QString);
            bool setExistsStatus(bool);
            int setSize(int);
    };

    std::vector<File> trackingFiles;
    int size;
    ILoger * loger;
    FileManager(ILoger* loger = nullptr, QObject *parent = nullptr);
    virtual ~FileManager() {}
    FileManager(FileManager const&); // реализация не нужна
    FileManager& operator= (FileManager const&); // и тут

public:
    static FileManager& InstanceFileManager(){
        static FileManager fileManager;
        return fileManager;
    }

    void addTrackedFile(const QString &filePath);

    bool findFileInTrackingFiles(const QString &filePath);

    void setLoger(ILoger *loger);

signals:
    void fileChanged(QString);
};

#endif // FILEMANAGER_H
