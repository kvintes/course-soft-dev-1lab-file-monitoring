#ifndef FILE_H
#define FILE_H
#include <QString>
#include <QFileInfo>
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

#endif // FILE_H
