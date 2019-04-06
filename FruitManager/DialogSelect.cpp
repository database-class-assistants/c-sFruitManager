#include "DialogSelect.h"
#include "ui_DialogSelect.h"
#include "FruitDaoImp.h"
#include "DBHelper.h"
#include <QDebug>
#include <QHeaderView>
DialogSelect::DialogSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSelect)
{
    ui->setupUi(this);

    model = new QSqlQueryModel(ui->tableView);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

DialogSelect::~DialogSelect()
{
    delete ui;
}

