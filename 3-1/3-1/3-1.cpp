#include <iostream>
#include <cmath>


/**
* \brief расчет функции.
* \param x - аргумент функции.
* \return  значение функции.
*/
double get(const double x);
/**
*\brief вычисляет значение заданной функции
*\param x - аргумент
*\return значение функции
*/
bool checkValid(const double x);
/**
* \brief Точка входа в программу.
* \return Возвращает 0 в случае успешного выполнения.
*/
int main()
{
	double x = -2;
	const double step = 0.001;
	const double border = 0.2;
	while (x <= step)
	{
		if (checkValid(x))
			std::cout << "for x= " << x << get(x) << "\n";
		else
			std::cout << "the function does not exit at this point" << x << "\n";
		x += step;
	}
	return 0;
}


double get(const double x)
{
	return log(1 / (2 * x + x * x));
}
bool checkValid(double x)
{
	return x < 0;
}
