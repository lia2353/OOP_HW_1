#ifndef ZAD1_CC_INCLUDED
#define ZAD1_CC_INCLUDED

#include "zad1.h"

/**
* Създава вектор със стойности 0
*/
Vector3D::Vector3D(): x(0), y(0), z(0)
{
}

/**
* Създава вектор по зададените стойности за компонентите x, y и z, където
* x, y и z са зададени спрямо правоъгълна координатна система
* @param x
* @param y
* @param z
*/
Vector3D::Vector3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

/**
* Деструктор за класа Vector3D
*/
Vector3D::~Vector3D()
{
}

/**
* Създава вектор със стойности на компонентите x, y и z ражни на стойностите
* на компонентите на подадения вектор otherVector
* @param otherVector вектор
*/
Vector3D::Vector3D(const Vector3D& otherVector)
{
    x = otherVector.x;
    y = otherVector.y;
    z = otherVector.z;
}

/**
* Предоставя възможност за приравняване на вектори
* @param otherVector вектор
* @return this вектор
*/

Vector3D& Vector3D::operator=(const Vector3D& otherVector)
{
    if(this != &otherVector)
    {
        x = otherVector.x;
        y = otherVector.y;
        z = otherVector.z;
    }
    return *this;
}

/**
* Връща стойността за x
* @return x
*/
double Vector3D::getX() const
{
    return x;
}

/**
* Връща стойността за y
* @return y
*/
double Vector3D::getY() const
{
    return y;
}

/**
* Връща стойността за z
* @return z
*/
double Vector3D::getZ() const
{
    return z;
}

/**
* Предоставя възможност за събиране на вектори
* @param secondVector вектор
* @return Нов вектор
*/
Vector3D Vector3D::operator+(const Vector3D& secondVector) const
{
    Vector3D newVector(x+secondVector.x, y+secondVector.y, z+secondVector.z);
    return newVector;
}

/**
* Предоставя възможност за изваждане на вектори
* @param secondVector вектор
* @return Нов вектор
*/
Vector3D Vector3D::operator-(const Vector3D& secondVector) const
{
    Vector3D newVector(x-secondVector.x, y-secondVector.y, z-secondVector.z);
    return newVector;
}

/**
* Връща нов вектор с променен знак
* @return Нов вектор с променен знак
*/
Vector3D Vector3D::operator-() const
{
    /*
    Vector3D newVector(x*(-1), y*(-1), z*(-1));
    return newVector;
    */
    return (-1)*(*this);
}

/**
* Умножава векторът с числото number
* @param number - число с което се умножава векторът
* @return Нов вектор
*/
Vector3D Vector3D::operator*(double number) const
{
    /*
    Vector3D newVector(x*number, y*number, z*number);
    return newVector;
    */
    return number*(*this);
}

/**
* Умножава число с вектор
* @param number - число
* @param vector - вектор
* @return Нов вектор
*/
Vector3D operator*(double number, const Vector3D& vector)
{
    Vector3D newVector(vector.x*number, vector.y*number, vector.z*number);
    return newVector;
}


/**
* Предоставя възможност за въвеждане на данни за вектор от стандартния вход, като
* трябвада бъде спазен следния формат:
* (x,y,z)
*/
std::istream& operator>>(std::istream& iStream, Vector3D& vector)
{
    char buffer; //в тази променлива се четат '(' и ','
    iStream >> buffer; //'('
    iStream >> vector.x;
    iStream >> buffer; //','
    iStream >> vector.y;
    iStream >> buffer; //','
    iStream >> vector.z;
    iStream >> buffer; //')'

    return iStream;
}

/**
* Предоставя възможност за визуализиране (извеждане) на стойностите в следния формат:
* (x, y, z)
*/
std::ostream& operator<<(std::ostream& oStream, const Vector3D& vector)
{
    oStream << '(' << vector.x << ',' << vector.y << ',' << vector.z << ')';
    return oStream;
}

#endif
