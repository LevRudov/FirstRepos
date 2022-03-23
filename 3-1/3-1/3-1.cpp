#include <iostream>
#include <cmath>


/**
* \brief расчет функции.
* \param x - аргумент функции.
* \return  значение функции.
*/
double get(const double x, int y);
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
	int y = 0;
	y = get(x, y);
	while (x <= step)
	{
		if (checkValid(x))
			std::cout << "for x= " << x << " y=" << get(x, y) << "\n";
		else
			std::cout << "invalid x:" << x << "\n";
		y = get(x, y);
		x += border;
	}
	return 0;
}


double get(const double x, int y)
{
	return log(1 / (y + 2 * x + x * x));
}
bool checkValid(double x)
{
	return x < 0;
}
