#include "dialogpurchase.h"
#include "ui_dialogpurchase.h"

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
