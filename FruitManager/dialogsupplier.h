#ifndef DIALOGSUPPLIER_H
#define DIALOGSUPPLIER_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QHeaderView>
#include <QThread>
#include <QDateTime>
#include <QTimer>

namespace Ui {
class DialogSupplier;
}

class DialogSupplier : public QWidget
{
    Q_OBJECT

public:
    explicit DialogSupplier(QWidget *parent = 0);
    void showAllSuppliers();
    ~DialogSupplier();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::DialogSupplier *ui;
    QSqlQueryModel *model;
};

#endif // DIALOGSUPPLIER_H
