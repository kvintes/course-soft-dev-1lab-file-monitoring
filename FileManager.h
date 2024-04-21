#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QObject>

#include "File.h"
#include "ILoger.h"
#include <QSet>
#include <iostream>
#include <QDebug>
#include <vector>

class FileManager:public QObject
{
    Q_OBJECT
private:
    std::vector<File> trackingFiles;
    int size;
    ILoger * loger;
public:
    FileManager(ILoger* loger = nullptr, QObject *parent = nullptr);

    void addTrackedFile(const QString &filePath);

    bool findFileInTrackingFiles(const QString &filePath);

    void setLoger(ILoger *loger);
    virtual ~FileManager() = default;

signals:
    void fileChanged(QString);
};

#endif // FILEMANAGER_H
