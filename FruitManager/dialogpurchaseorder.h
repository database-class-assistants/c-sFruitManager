#ifndef DIALOGPURCHASEORDER_H
#define DIALOGPURCHASEORDER_H

#include <QDialog>

namespace Ui {
class DialogPurchaseOrder;
}

class DialogPurchaseOrder : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPurchaseOrder(QWidget *parent = 0);
    ~DialogPurchaseOrder();

private:
    Ui::DialogPurchaseOrder *ui;
};

#endif // DIALOGPURCHASEORDER_H
