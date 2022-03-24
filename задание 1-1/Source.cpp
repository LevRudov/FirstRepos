#include <cmath>
#include <iostream>
#define _USE_MATH_DEFINES
/**
* \ brief вычисление заданной функции a(x,y,z)
* \ param переменные функции x,y,z
* \ return выимсленное значение функции A
*/
double getA(const double x, const double y, const double z);
/**
* \ brief вычисление заданной функции b(x,y,z)
* \ param переменные функции x,y,z
* \ return вычисленное значение функции B
*/
double getB(const double x, const double y, const double z);
/**
* \brief функция main
* \param
* \return 0,если программа выполнена
*/
int main()
{
	const double x = 0.29;
	const double y = 3.7;
	const double z = -1;
	std::cout << "x = " << x << " y = " << y << " z = " << z << " a = " << getA(x, y, z) << " b = " << getB(x, y, z);
	return 0;
}
double getA(const double x, const double y, const double z)
{
	return 3 * pow(x, y) * log(y) + exp(z * x);
}
double getB(const double x, const double y, const double z)
{
	return abs(2 * y * z) / pow(sin(x), 2) - x * x / 3;
}
