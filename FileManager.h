#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "File.h"
#include "ILoger.h"
#include <QSet>
#include <iostream>
#include <QDebug>

class FileManager
{
private:
    File ** trackedFiles;
    int size;
    ILoger * loger;
public:
    FileManager(const QString &filePaths, const QString &sep);
    FileManager(File *);
    ~FileManager();

    int getSize();
    void setLoger(ILoger *);
    void setTrackedFiles(File *);
    QString checkChanges();

signals:
    fileChanged();
};

#endif // FILEMANAGER_H
