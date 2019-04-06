#include "login.h"
#include "ui_login.h"
#include <QDebug>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    dialogWarehouse = new DialogWarehouse(this);
    dialogWarehouse->setWindowModality(Qt::ApplicationModal);
//    QObject::connect(this,SIGNAL(sigWarehouse(const Fruit &)),dialogWarehouse,SLOT(onSigWarehouse(const Fruit &)));
}

login::~login()
{
    delete ui;
}
void login::onUserLogin(const User &user){
    qDebug()<<user.getName();
    ui->le_username->setText(user.getName());
}

void login::on_pushButton_clicked()
{
    dialogWarehouse->show();
}
