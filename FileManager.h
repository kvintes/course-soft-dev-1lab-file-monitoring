#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <QObject>

#include "File.h"
#include "ILoger.h"
#include <QSet>
#include <iostream>
#include <QDebug>

class FileManager:public QObject
{
    Q_OBJECT
private:
    File ** trackedFiles;
    int size;
    ILoger * loger;
public:
    FileManager(const QString &filePaths, const QString &sep, QObject *parent = nullptr);
    FileManager(File *);
    virtual ~FileManager();

    void checkStates();
    void checkFileChanges(QFileInfo *fileNow, File * fileOld);

    QString getInfo();
    int getSize();

    void setLoger(ILoger *);
    void setTrackedFiles(File *);
    QString checkChanges();

signals:
    void fileChanged(QString);
};

#endif // FILEMANAGER_H
