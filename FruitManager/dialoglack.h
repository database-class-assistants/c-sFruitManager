#ifndef DIALOGLACK_H
#define DIALOGLACK_H

#include <QDialog>
#include <QSqlQueryModel>
#include "dbhelper.h"
#include "fruitdaoimp.h"

namespace Ui {
class DialogLack;
}

class DialogLack : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLack(QWidget *parent = nullptr);
    ~DialogLack();

private slots:
    void on_btn_flush_clicked();

private:
    Ui::DialogLack *ui;
    QSqlQueryModel *model;

    void flush();
};

#endif // DIALOGLACK_H
