#include "login.h"
#include "ui_login.h"
#include <QDebug>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    dialogWarehouse = new DialogWarehouse(this);
    dialogLack = new DialogLack();
    dialogSale = new DialogSale();
    dialogSupplier = new DialogSupplier();
    dialogPurchase  = new DialogPurchase();

    dialogWarehouse->setWindowModality(Qt::ApplicationModal);
    dialogLack->setWindowModality(Qt::ApplicationModal);
    dialogSale->setWindowModality(Qt::ApplicationModal);
    dialogSupplier->setWindowModality(Qt::ApplicationModal);
    dialogPurchase->setWindowModality(Qt::ApplicationModal);

}

login::~login()
{
    delete ui;
}
void login::onUserLogin(const User &user){
    qDebug()<<user.getName();
    ui->le_username->setText(user.getName());
}

void login::on_btn_entrepot_clicked()
{
    dialogWarehouse->show();
}

void login::on_btn_need_clicked()
{
    dialogLack->show();
}

void login::on_pushButton_clicked()
{
    dialogSale->show();
}

void login::on_btn_supplier_clicked()
{
    dialogSupplier->show();
}

void login::on_btn_purchase_clicked()
{
    dialogPurchase->show();
}
