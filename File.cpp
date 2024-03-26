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
QString File::getPath(){
    return filePath;
}
bool File::getExistsStatus(){
    return isExists;
}
int File::getSize(){
    return fileSize;
}
