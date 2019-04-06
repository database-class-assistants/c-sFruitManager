#include "dbhelper.h"
#include <QDebug>
DBHelper *DBHelper::instance = NULL;

DBHelper::DBHelper()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("long");
}
void DBHelper::connectDatabase()
{
    db.setDatabaseName("fruit");
    qDebug()<<"true";
    bool ret = db.open();
    if(ret){qDebug()<<"open db success";}
    else{qDebug()<<"open db failed";}
}

void DBHelper::disconnectDatabase()
{
    db.close();
    db.removeDatabase("fruit");
}


//开门
DBHelper *DBHelper::getInstance()
{
    if(instance == NULL)
    {
        instance = new DBHelper();
    }
    return instance;
}
