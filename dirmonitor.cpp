#include "dirmonitor.h"

dirMonitor::dirMonitor(QString name, QString path):name(name),path(path)
{
    dir = QDir(path);
}

void dirMonitor::run(){
    while(true){
        QDir new_dir = QDir(path);
        if(dir.count()!=new_dir.count()){
            // = Есть изменения по кол-ву файлов
            emit dirChanged();
            dir = new_dir;
        }
    }
}
