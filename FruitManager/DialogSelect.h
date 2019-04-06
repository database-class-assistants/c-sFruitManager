#ifndef DIALOGSELECT_H
#define DIALOGSELECT_H

#include <QDialog>
#include <QSqlQueryModel>
#include <QTimer>
namespace Ui {
class DialogSelect;
}

class DialogSelect : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSelect(QWidget *parent = 0);
    ~DialogSelect();
private:
    Ui::DialogSelect *ui;
    QSqlQueryModel *model;
};

#endif // DIALOGSELECT_H
