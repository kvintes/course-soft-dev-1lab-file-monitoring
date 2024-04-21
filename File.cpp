#include "FileManager.h"

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
QString FileManager::File::getPath(){
    return filePath;
}
bool FileManager::File::getExistsStatus(){
    return isExists;
}
int FileManager::File::getSize(){
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
