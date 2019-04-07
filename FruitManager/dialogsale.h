#ifndef DIALOGSALE_H
#define DIALOGSALE_H

#include <QDialog>

namespace Ui {
class DialogSale;
}

class DialogSale : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSale(QWidget *parent = nullptr);
    ~DialogSale();

private:
    Ui::DialogSale *ui;
};

#endif // DIALOGSALE_H
