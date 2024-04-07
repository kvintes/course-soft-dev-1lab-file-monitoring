#include "file.h"

File::File(const QString &filePath) {
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
File::File() {
    this->filePath = QString("");
    this->isExists = false;
    this->fileSize = 0;
}
QString File::getPath(){
    return filePath;
}
bool File::getExistsStatus(){
    return isExists;
}
int File::getSize(){
    return fileSize;
}

QString File::setPath(QString path){
    return filePath = path;
}
bool File::setExistsStatus(bool status){
    return isExists = status;
}
int File::setSize(int size){
    return fileSize = size;
}
