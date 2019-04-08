#include "dialogsupplier.h"
#include "ui_dialogsupplier.h"

DialogSupplier::DialogSupplier(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialogSupplier)
{
    ui->setupUi(this);
}

DialogSupplier::~DialogSupplier()
{
    delete ui;
}
