#include "dialogpurchaseorder.h"
#include "ui_dialogpurchaseorder.h"

DialogPurchaseOrder::DialogPurchaseOrder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPurchaseOrder)
{
    ui->setupUi(this);
}

DialogPurchaseOrder::~DialogPurchaseOrder()
{
    delete ui;
}
