#include "dialogwarehouse.h"
#include "ui_dialogwarehouse.h"
#include <fruitdaoimp.h>
#include <QSqlQuery>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include <QMessageBox>

DialogWarehouse::DialogWarehouse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWarehouse)
{
    ui->setupUi(this);
    /**将数据模型与QTableView绑定**/
    model = new QSqlQueryModel(ui->tableView);/**将数据模型与QTableView绑定**/
    /**tableView列宽等宽自适应**/
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    showAllFruits();



}


void DialogWarehouse::showAllFruits()
{
    DBHelper *helper =  DBHelper::getInstance();
    helper->connectDatabase();
//    QSqlQuery query;
    model->setQuery("select fruitName as '水果名',"
                    "fruitPrice as '单价￥/0.5kg',"
                    "fruitNum as '数量/kg' from fruit_tb;");
    ui->tableView->setModel(model);

    helper->disconnectDatabase();

}

DialogWarehouse::~DialogWarehouse()
{
    delete ui;
}

void DialogWarehouse::on_pushButton_4_clicked(){

}

void DialogWarehouse::on_btn_delete_clicked(){

}


void DialogWarehouse::on_btn_del_clicked()
{
    int row = ui->tableView->selectionModel()->currentIndex().row();
    qDebug()<<row;
}
void DialogWarehouse::on_btn_add_clicked()
{
    QMessageBox::critical(this,"警告","密码错误");
}

