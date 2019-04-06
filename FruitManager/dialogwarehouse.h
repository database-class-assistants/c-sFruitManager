#ifndef DIALOGWAREHOUSE_H
#define DIALOGWAREHOUSE_H

#include <QDialog>
#include <QStandardItemModel>
#include <QSqlQueryModel>
#include <dbhelper.h>

namespace Ui {
class DialogWarehouse;
}

class DialogWarehouse : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWarehouse(QWidget *parent = 0);
    void showAllFruits();
    ~DialogWarehouse();

private slots:
    void on_pushButton_4_clicked();

    void on_btn_delete_clicked();

    void on_btn_del_clicked();

    void on_btn_add_clicked();

private:
    Ui::DialogWarehouse *ui;
    QSqlQueryModel *model;
};

#endif // DIALOGWAREHOUSE_H
