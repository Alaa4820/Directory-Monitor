#include "qdirectory.h"

QDirectory::QDirectory(): _map(){
    _path = QDir::currentPath() + "/myDir";
}

QDirectory::~QDirectory(){}

void QDirectory::loadFile(){
    QDir directory(_path);
    QStringList files = directory.entryList(QDir::Files);
    for(QString filename: files){
        QFile file(_path+"/"+filename);
        _map.insert(filename, QFileInfo(file).lastModified());
    }
}

const QMap<QString, QDateTime> &QDirectory::map() const{
    return _map;
}


