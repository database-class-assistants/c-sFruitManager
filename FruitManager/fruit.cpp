#include "fruit.h"

Fruit::Fruit(const QString &fruitName, const double &fruitPrice, const double &fruitNum)
    :fruitName(fruitName),fruitPrice(fruitPrice),fruitNum(fruitNum)
{

}

QString Fruit::getFruitName() const
{
    return fruitName;
}

double Fruit::getFruitPrice() const
{
    return fruitPrice;
}

double Fruit::getFruitNum() const
{
    return fruitNum;
}
