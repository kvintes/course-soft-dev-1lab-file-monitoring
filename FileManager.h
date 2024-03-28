#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include "File.h"
#include "ILoger.h"

class FileManager
{
private:
    File * trackedFiles;
    ILoger * loger;
public:
    FileManager(const QString &filePaths, const QString &sep);
    FileManager(File *);
    ~FileManager();

    void setLoger(ILoger *);
    void setTrackedFiles(File *);
    QString checkChanges();

signals:
    fileChanged();
};

#endif // FILEMANAGER_H
