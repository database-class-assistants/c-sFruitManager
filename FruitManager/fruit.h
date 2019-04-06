#ifndef FRUIT_H
#define FRUIT_H
#include<QString>

class Fruit
{
public:
    Fruit(const QString &fruitName,const double &fruitPrice,const double &fruitNum);
    QString getFruitName()const;
    double getFruitPrice()const;
    double getFruitNum()const;
private:
    QString fruitName;
    double fruitPrice;
    double fruitNum;
};

#endif // FRUIT_H
