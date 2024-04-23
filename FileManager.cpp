#include "FileManager.h"
FileManager::FileManager(ILoger* loger, QObject *parent):QObject(parent){
    this->setLoger(loger);
}
void FileManager::setLoger(ILoger *loger){
    if(loger && !this->loger){
        this->loger = loger;
        connect(this, &FileManager::fileChangedMessage, this->loger, &ILoger::outputMessage);
    }
}
void FileManager::addTrackedFile(const QString &filePath){
    //проверить что такого файла нет
    if(this->findFileInTrackingFiles(filePath)) {
        return;
    }
    //добавить
    File addingFile(filePath);
    this->trackingFiles.push_back(addingFile);
}
bool FileManager::findFileInTrackingFiles(const QString &filePath){
    for(auto file : this->trackingFiles){
        if(file.getPath() == filePath){
            return true;
        }
    }
    return false;
}
void FileManager::checkFilesStates(){
    if(this->trackingFiles.size() > 0){
        QFileInfo fileInfoNow;
        for(auto & file : this->trackingFiles){
            fileInfoNow.setFile(file.getPath());
            this->checkFileChanges(fileInfoNow, file);
        }
        return;
    }
    emit fileChangedMessage(QString("LOG: trackedFiles are absent"));
}
void FileManager::checkFileChanges(const QFileInfo& fileNow, File& fileOld){
    QString message = "файл: "+fileOld.getPath();
    if(fileNow.exists() == fileOld.getExistsStatus()){
        if(!fileNow.exists() || fileNow.size() == fileOld.getSize()) return;//изменений нет
        //изменился размер
        message+=QString(" существует ")
                   +QString(" старый размер: ")+QString::number(fileOld.getSize())
                   +QString(" новый размер: ")+QString::number(fileNow.size());
        fileOld.setSize(fileNow.size());//сохранили новый размер
    } else {
        if(fileNow.exists()){//файл создали
            message+=QString(" существует ")+QString(" размер: ")+QString::number(fileNow.size());
        } else { //файл удалили
            message+=QString(" НЕ существует ");
        }
        fileOld.setSize(fileNow.size());
        fileOld.setExistsStatus(fileNow.exists());
    }
    emit fileChangedMessage(message);
}
QString FileManager::getInfo() const{
    QString info = "begining settings: \n";
    if(this->trackingFiles.size() > 0){
        for(auto file : this->trackingFiles){
            info += " path: " + file.getPath();
            info += "\n status: ";
            if(file.getExistsStatus()){
                info += " Существует ";
            } else {
                info += " НЕ cуществует ";
            }
            info += "\n size: " + QString::number(file.getSize());
            info += "\n";
        }
    }
    return info;
}



FileManager::File::File(const QString &filePath) {
    if(filePath.size() != 0){
        QFileInfo *temp = new QFileInfo(filePath);
        if(temp){
            this->filePath = QString(filePath);
            this->isExists = temp->exists();
            this->fileSize = temp->size();
            delete temp;
        }
    }
}
FileManager::File::File() {
    this->filePath = QString("");
    this->isExists = false;
    this->fileSize = 0;
}
QString FileManager::File::getPath() const{
    return filePath;
}
bool FileManager::File::getExistsStatus() const{
    return isExists;
}
int FileManager::File::getSize() const{
    return fileSize;
}

QString FileManager::File::setPath(QString path){
    return filePath = path;
}
bool FileManager::File::setExistsStatus(bool status){
    return isExists = status;
}
int FileManager::File::setSize(int size){
    return fileSize = size;
}



