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
    for (const auto &x : setFilePaths){
        qDebug() << x;
    }

}
FileManager::~FileManager(){

}

// void setLoger(ILoger *);
// void setTrackedFiles(File *);
// QString checkChanges();
