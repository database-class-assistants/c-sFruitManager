#include "dialogsale.h"
#include "ui_dialogsale.h"

DialogSale::DialogSale(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSale)
{
    ui->setupUi(this);
}

DialogSale::~DialogSale()
{
    delete ui;
}
