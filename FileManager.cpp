#include "FileManager.h"
// File * trackedFiles;
// ILoger * loger;

// FileManager::FileManager(File *files) {

// }
FileManager::FileManager(const QString &argfilePaths, const QString &sep){
    QString filePaths = argfilePaths+sep;
    QSet<QString> setFilePaths;
    QString filePath;
    for(int i = 0; i < filePaths.size(); ++i){
        int j = 0;
        for(; j < sep.size(); j++){
            if(filePaths[i] != sep[j]){
                j = -1;
                break;
            }
        }
        if(j != sep.size()){
            filePath += filePaths[i];

        } else {
            if(!filePath.isEmpty()){
                setFilePaths.insert(filePath);
            }
            filePath = "";
        }
    }//множество путей файлов
    // for (const auto &x : setFilePaths){
    //     qDebug() << x;
    // }

    this->size = setFilePaths.size();
    trackedFiles = new File* [this->size];
    int j = 0;
    for (const auto& path : setFilePaths)
    {
        qDebug() << path;
        trackedFiles[j++] = new File(path);
    }
}
FileManager::~FileManager(){
    if(this->trackedFiles){
        if(this->getSize() > 0){
            for(int i = 0; i < this->getSize(); ++i){
                delete trackedFiles[i];
            }
        }
        delete trackedFiles;
    }
}
int FileManager::getSize(){
    return this->size;
}
QString FileManager::getInfo(){
    if(this->trackedFiles){
        QString info;
        if(this->getSize() > 0){
            for(int i = 0; i < this->getSize(); ++i){
                info += "path: " + trackedFiles[i]->getPath();
                info += "\tstatus: " + trackedFiles[i]->getExistsStatus();
                info += "\tsize: " + trackedFiles[i]->getSize();
                info += "\n";
            }
        }
        return info;
    }
}

void FileManager::checkStates(){
    if(this->trackedFiles){
        if(this->getSize()>0){
            for(int i = 0; i < this->getSize(); ++i){
                QFileInfo *temp = new QFileInfo(trackedFiles[i]->getPath());
                if(temp){
                    this->checkFileChanges(temp, trackedFiles[i]);
                    delete temp;
                }
            }
        }
    } else {
        QString message = "null pointers checkStates";
        this->loger->outputMessage(message);
    }
}
void FileManager::checkFileChanges(QFileInfo *fileNow, File* fileOld){
    QString message;
    if(fileNow && fileOld){
        message = "файл: "+fileOld->getPath();
        if(fileNow->exists() == fileOld->getExistsStatus()){
            if(!fileNow->exists() || fileNow->size() == fileOld->getSize()) return;//изменений нет
            //изменился размер
            message+=QString(" существует ")
                    +QString(" старый размер: ")+QString::number(fileOld->getSize())
                    +QString(" новый размер: ")+QString::number(fileNow->size());
            fileOld->setSize(fileNow->size());//сохранили новый размер
        } else {
            if(fileNow->exists()){//файл создали
                message+=QString(" существует ")+QString(" размер: ")+QString::number(fileNow->size());
                fileOld->setSize(fileNow->size());
                fileOld->setExistsStatus(fileNow->exists());
            } else { //файл удалили
                message+=QString(" НЕ существует ");
                fileOld->setSize(fileNow->size());
                fileOld->setExistsStatus(fileNow->exists());
            }
        }
        this->loger->outputMessage(message);
    }
    message = "null pointers checkFileChanges";
    this->loger->outputMessage(message);
}

void FileManager::setLoger(ILoger *loger){
    this->loger = loger;
}
// void setTrackedFiles(File *);
// QString checkChanges();
