#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "user.h"
#include "QString"
#include "dialogwarehouse.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);

    ~login();

private slots:
    void onUserLogin(const User &user);

    void on_pushButton_clicked();

private:
    Ui::login *ui;
    DialogWarehouse *dialogWarehouse;
};

#endif // LOGIN_H
