#ifndef DIALOGPURCHASE_H
#define DIALOGPURCHASE_H

#include <QWidget>

namespace Ui {
class DialogPurchase;
}

class DialogPurchase : public QWidget
{
    Q_OBJECT

public:
    explicit DialogPurchase(QWidget *parent = 0);
    ~DialogPurchase();

private:
    Ui::DialogPurchase *ui;
};

#endif // DIALOGPURCHASE_H
