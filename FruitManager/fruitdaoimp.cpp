#include "fruitdaoimp.h"

FruitDaoImp::FruitDaoImp()
{

}

QSqlQuery FruitDaoImp::selectFruits(){
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    query.prepare("select * from om_entrepot ");
    query.exec();
    helper->disconnectDatabase();
    return query;
}

QSqlQuery FruitDaoImp::selectFruitByName(QString fruitName){
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    query.prepare("select fruitName ,fruitPrice, fruitNum from om_entrepot where fruitName = :fruitName;");
    query.bindValue(":fruitName",fruitName);
    query.exec();
    helper->disconnectDatabase();
    return query;
}

QSqlQuery FruitDaoImp::selectFruitByPrice(double fruitPrice){
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    query.prepare("select fruitName ,fruitPrice, fruitNum from fruit_tb where fruitPrice = :fruitPrice;");
    query.bindValue(":fruitPrice",fruitPrice);
    query.exec();
    helper->disconnectDatabase();
    return query;
}

QSqlQuery FruitDaoImp::selectFruitByNum(double fruitNum){
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    query.prepare("select fruitName ,fruitPrice, fruitNum from om_entrepot where fruitNum = :fruitNum;");
    query.bindValue(":fruitNum",fruitNum);
    query.exec();
    helper->disconnectDatabase();
    return query;
}

bool FruitDaoImp::insertFruit(const Fruit &fruit) {
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    bool ret;
    query.prepare("insert into om_entrepot(fruitName,fruitPrice,fruitNum)"
                  "values(:fruitName,:fruitPrice,:fruitNum);");
    query.bindValue(":fruitName",fruit.getFruitName());
    query.bindValue(":fruitPrice",fruit.getFruitPrice());
    query.bindValue(":fruitNum",fruit.getFruitPrice());
    ret = query.exec();

    if(ret){qDebug()<<"DaoImp insert success";}
    else{qDebug()<<query.lastError().text();}

    helper->disconnectDatabase();
    return ret;
}

bool FruitDaoImp::deleteFruit(const QString &fruitName) {
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    bool ret;
    query.prepare("delete from om_entrepot where fruitName = :fruitName");
    query.bindValue(":fruitName",fruitName);
    ret = query.exec();

    if(ret){qDebug()<<"DaoImp insert success";}
    else{qDebug()<<query.lastError().text();}

    helper->disconnectDatabase();
    return ret;
}

bool FruitDaoImp::updateFruit(const Fruit &fruit) {
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    bool ret;
    query.prepare("update om_entrepot "
                  "set fruitName = :fruitName, "
                  "fruitPrice = :fruitPrice, "
                  "fruitNum = fruitNum "
                  "where fruitName = :fruitName");
    query.bindValue(":fruitName",fruit.getFruitName());
    query.bindValue(":fruitPrice",fruit.getFruitPrice());
    query.bindValue(":fruitNum",fruit.getFruitNum());
    qDebug() << fruit.getFruitName() << "|"
           << fruit.getFruitPrice() << "|"
           << fruit.getFruitNum() << "|";
    ret = query.exec();

    if(ret){qDebug()<<"修改成功";}
    else{qDebug()<<query.lastError().text();}

    helper->disconnectDatabase();
    return ret;
}
