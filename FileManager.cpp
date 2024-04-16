#include "FileManager.h"
FileManager::FileManager(const QString &argfilePaths, const QString &sep, QObject *parent):QObject(parent){
    QString filePaths = argfilePaths+sep;
    QSet<QString> setFilePaths;
    QString filePath;
    for(int i = 0; i < filePaths.size(); ++i){
        int j = 0;int i_temp = i;
        for(; j < sep.size(); j++, i++){
            if(filePaths[i] != sep[j]){
                j = -1;
                i = i_temp;
                break;
            }
        }
        if(j != sep.size() || sep.size() == 0){
            filePath += filePaths[i];
        } else {
            if(!filePath.isEmpty()){
                setFilePaths.insert(filePath);
            }
            filePath = "";
            i--;
        }
    }
    if(setFilePaths.size() > 0){
        this->size = setFilePaths.size();
        trackedFiles = new File* [this->size];
        int j = 0;
        for (const auto& path : setFilePaths)
        {
            qDebug() <<QString("путь:  ") <<path<< QString(" добавлен ")<<Qt::endl;
            trackedFiles[j++] = new File(path);
        }
    } else {
        trackedFiles = nullptr;
        size = 0;
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
    QString info = "begining settings: \n";
    if(this->trackedFiles){
        if(this->getSize() > 0){
            for(int i = 0; i < this->getSize(); ++i){
                info += " path: " + trackedFiles[i]->getPath();
                info += "\n status: ";
                if(trackedFiles[i]->getExistsStatus()){
                    info += " Существует ";
                } else {
                    info += " НЕ cуществует ";
                }
                info += "\n size: " + QString::number(trackedFiles[i]->getSize());
                info += "\n";
            }
        }
    }
    return info;
}
void FileManager::checkStates(){
    if(this->trackedFiles){
        if(this->getSize()>0){
            QFileInfo temp;
            for(int i = 0; i < this->getSize(); ++i){
                temp.setFile(trackedFiles[i]->getPath());
                this->checkFileChanges(&temp, trackedFiles[i]);
            }
        } else {
            QString message = "LOG: FileManager is Empty";
            emit fileChanged(message);
        }
    } else {
        QString message = "LOG: trackedFiles are absent";
        emit fileChanged(message);
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
    } else {
        message = "LOG: null pointers checkFileChanges";
    }
    emit fileChanged(message);
}
void FileManager::setLoger(ILoger *loger){
    this->loger = loger;
    connect(this, &FileManager::fileChanged, this->loger, &ILoger::outputMessage);
}
// void setTrackedFiles(File *);
// QString checkChanges();
