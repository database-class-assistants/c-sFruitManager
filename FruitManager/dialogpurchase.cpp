#include "dialogpurchase.h"
#include "ui_dialogpurchase.h"
#include <dbhelper.h>
#include <QComboBox>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QDateTime>
#include <QStringList>
#include "fruit.h"
#include "fruitdaoimp.h"
#include "fruitdao.h"

DialogPurchase::DialogPurchase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogPurchase)
{
    ui->setupUi(this);
}

DialogPurchase::~DialogPurchase()
{
    delete ui;
}

void DialogPurchase::on_le_fruit_name_textChanged(const QString &arg1)
{
    ui->cb_supplier->clear();
    ui->le_price->clear();
    ui->le_address->clear();
}

void DialogPurchase::on_cb_supplier_activated(const QString &arg1)
{
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;
    QString supplier = ui->cb_supplier->currentText();
    query.prepare("select price, address from om_supplier where name = :supplier;");
    query.bindValue(":supplier", supplier);
    query.exec();

    while(query.next()){
        ui->le_price->setText(query.value(0).toString());
        ui->le_address->setText(query.value(1).toString());
    }


    helper->disconnectDatabase();
}

void DialogPurchase::on_le_fruit_name_editingFinished()
{
    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();

    QString fruitName ;
    fruitName = ui->le_fruit_name->text();

    QSqlQuery query;
    query.prepare("select name from om_supplier where fruitName = :fruitName;");
    query.bindValue(":fruitName", fruitName);
    query.exec();

    if(query.size() == 0){
        QMessageBox::information(this,"警告"," 该水果没有供应商供应");
        return ;
    }

    while(query.next()){
        ui->cb_supplier->addItem(query.value(0).toString());
    }
//    QStringList strList;
//    strList <<"香蕉"<<"水果";
//    ui->cb_supplier->addItems(strList);
    helper->disconnectDatabase();
}

void DialogPurchase::on_pushButton_clicked()
{
    int fruitId;
    QString fruitName;
    int supplierId;
    QString supplierName;
    QString address;
    double price;
    double num;
    QString date;
    int is_update = 0;


    if(ui->cb_supplier->currentText().isEmpty()||
            ui->le_fruit_name->text().isEmpty() ||
            ui->le_num->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","请完善信息");
        return;
    }

    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;

    supplierName = ui->cb_supplier->currentText();
    fruitName = ui->le_fruit_name->text();
    address = ui->le_address->text();
    price = ui->le_price->text().toDouble();
    num = ui->le_num->text().toDouble();
    QDateTime current_date_time = QDateTime::currentDateTime();
    date = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
//    qDebug()<<supplierName;

    //获取水果id
    query.prepare("select id from om_entrepot where fruitName = :fruitName;");
    query.bindValue(":fruitName", fruitName);
    query.exec();
    while(query.next()){
        fruitId = query.value(0).toString().toInt();
    }

    //获取供应商id
    query.prepare("select id from om_supplier where name = :supplierName;");
    query.bindValue(":supplierName", supplierName);
    query.exec();
    while(query.next()){
        supplierId = query.value(0).toString().toInt();
    }


    //执行采购单插入
    query.prepare("insert into om_purchase_order(fruit_id,fruit_name,number, price,supplier_id,supplier_name,date,is_update)"
                  "values(:fruitId, :fruitName, :num, :price, :supplierId, :supplierName, :date, :is_update);");
    query.bindValue(":fruitId", fruitId);
    query.bindValue(":fruitName", fruitName);
    query.bindValue(":num", num);
    query.bindValue(":price", price);
    query.bindValue(":supplierId", supplierId);
    query.bindValue(":supplierName", supplierName);
    query.bindValue(":date", date);
    query.bindValue(":is_update", is_update);

    bool ret = query.exec();

    if(ret){
        qDebug()<<"添加采购记录成功";
    }
    else{
        qDebug()<<"添加采购记录失败"<<query.lastError().text();
    }

    // 将采购的水果加入库存
    double fruitNum;
    double fruitPrice;
    double limited_number;
    query.prepare("select * from om_entrepot where fruitName = :fruitName;");
    query.bindValue(":fruitName", fruitName);
    query.exec();

    if(query.size() == 0){
        fruitNum = num;
        fruitPrice = price;
        limited_number = 0;
        Fruit fruit(fruitName,fruitPrice,fruitNum,limited_number);
        FruitDao *fd = new FruitDaoImp();
        bool ret = fd->insertFruit(fruit);
        if(ret)
        {
            qDebug()<<"插入成功";
        }
        else
        {
            qDebug()<<"插入失败";
        }
        delete(fd);
        fd=NULL;
    } else {
        while(query.next()){
            fruitNum = query.value(2).toString().toDouble() + num;
            fruitPrice = query.value(3).toString().toDouble();
            limited_number = query.value(4).toString().toDouble();

            Fruit fruit(fruitName,fruitPrice,fruitNum,limited_number);
            FruitDao *fd = new FruitDaoImp();
            bool ret = fd->updateFruit(fruit, fruitName);
            if(ret)
            {
                qDebug()<<"修改成功";
            }
            else
            {
                qDebug()<<"修改失败";
            }
            delete(fd);
            fd=NULL;
        }
    }


    helper->disconnectDatabase();
    this->close();

}
