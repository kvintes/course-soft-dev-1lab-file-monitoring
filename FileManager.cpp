#include "FileManager.h"
FileManager::FileManager(ILoger* loger, QObject *parent):QObject(parent){
    this->setLoger(loger);
}
void FileManager::setLoger(ILoger *loger){
    if(loger){
        this->loger = loger;
        connect(this, &FileManager::fileChanged, this->loger, &ILoger::outputMessage);
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



