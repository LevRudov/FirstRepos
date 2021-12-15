#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>

int main()
{
	double rad, degree, minutes, seconds;
	std::cout << "Введите радианы";
	std::cin >> rad;
	degree = (180 / M_PI) * rad;
	minutes = (60 * 180) / M_PI * rad;
	seconds = (3600 * 180) / M_PI * rad;
	std::cout << "Градусы" << degree << std::endl;
	std::cout << "Минуты" << minutes << std::endl;
	std::cout << "Секунды" << seconds << std::endl;
	return 0;
}