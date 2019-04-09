#include "DialogSelect.h"
#include "ui_DialogSelect.h"
#include "FruitDaoImp.h"
#include "DBHelper.h"
#include <QDebug>
#include <QMessageBox>
#include <QHeaderView>
#include <QTextCodec>
DialogSelect::DialogSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSelect)
{
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("utf8"));
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
//    if(!createConnection())
//           return 1;
    ui->setupUi(this);

    model = new QSqlQueryModel(ui->tableView);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DialogSelect::~DialogSelect()
{
    delete ui;
}


void DialogSelect::on_btn_select_clicked()
{
    if(ui->le_select->text().isEmpty() )
    {
        QMessageBox::critical(this,"警告","不允许为空");
        return;
    }

    DBHelper *helper =  DBHelper::getInstance();
    helper->connectDatabase();

    QSqlQuery query;
    query.prepare("select fruitName, fruitNum, fruitPrice, limited_number from om_entrepot where fruitName = :name;");
    query.bindValue(":name", ui->le_select->text());
    bool ret = query.exec();
    while(query.next()){
         qDebug() << query.value(0).toString() << "|"
                  << query.value(1).toString() << "|"
                  << query.value(2).toString();
    }
    if(ret){
        qDebug()<<"select from om_entrepot success";
    } else {
        qDebug()<<query.lastError().text();
    }

    model->setQuery("select fruitName as '水果名',"
                    "fruitNum as '数量/kg',"
                    "fruitPrice as '单价￥/500g', "
                    "limited_number as '最低数量/kg'  from om_entrepot where fruitName = " +
                    ui->le_select->text() +
                    ";");

    ui->tableView->setModel(model);

    helper->disconnectDatabase();
}
