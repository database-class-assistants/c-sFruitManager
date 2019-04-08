#include "dialogsupplier.h"
#include "ui_dialogsupplier.h"
#include <dbhelper.h>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include "supplierdaoimp.h"

DialogSupplier::DialogSupplier(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogSupplier)
{
    ui->setupUi(this);


    /**将数据模型与QTableView绑定**/
    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
    /**tableView列宽等宽自适应**/
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);


    showAllSuppliers();

}

DialogSupplier::~DialogSupplier()
{
    delete ui;
}

void DialogSupplier::showAllSuppliers()
{
    DBHelper *helper =  DBHelper::getInstance();
    helper->connectDatabase();

    model->setQuery("select name as '供应商',"
                    "fruitName as '水果名',"
                    "price as '单价￥/500g',"
                    "number as '数量/kg', "
                    "address as '地址',"
                    "telephone as '电话' from om_supplier;");
    ui->tableView->setModel(model);

    helper->disconnectDatabase();
}


void DialogSupplier::on_pushButton_5_clicked()
{

    QString fruitName;
    QString supplierName;
    QString address;
    double price;
    double number;
    QString telephone;


    if(ui->le_supplier->text().isEmpty()||
            ui->le_fruit_name->text().isEmpty() ||
            ui->le_price->text().isEmpty() ||
            ui->le_address->text().isEmpty() ||
            ui->le_number->text().isEmpty() ||
            ui->le_telephone->text().isEmpty())
    {
        QMessageBox::critical(this,"警告","请完善信息");
        return;
    }

    DBHelper *helper = DBHelper::getInstance();
    helper->connectDatabase();
    QSqlQuery query;

    supplierName = ui->le_supplier->text();
    fruitName = ui->le_fruit_name->text();
    address = ui->le_address->text();
    price = ui->le_price->text().toDouble();
    number = ui->le_number->text().toDouble();
    telephone = ui->le_telephone->text();


    //执行插入
    query.prepare("insert into om_supplier(name,fruitName, price,number,address,telephone)"
                  "values(:name, :fruitName, :price, :number, :address, :telephone);");
    query.bindValue(":name", supplierName);
    query.bindValue(":fruitName", fruitName);
    query.bindValue(":price", price);
    query.bindValue(":number", number);
    query.bindValue(":address", address);
    query.bindValue(":telephone", telephone);

    bool ret = query.exec();

    if(ret){
        qDebug()<<"添加供应商成功";
    }
    else{
        qDebug()<<"添加供应商失败"<<query.lastError().text();
    }

    helper->disconnectDatabase();
    showAllSuppliers();
}

void DialogSupplier::on_btn_flush_clicked()
{
    showAllSuppliers();
}
