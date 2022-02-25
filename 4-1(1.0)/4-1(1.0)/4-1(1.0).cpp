#include <sstream>
#include <iostream>
#include <cmatch>
#include <string>
#include <random>

using namespace std;
// генератор случайных чиселс равномерным распределением
class Rand_int
{
public:
	Rand_int(int low, int high) :dist{}
	int operator()() { return dist(re); }
	void seed(int s) { re.seed(s); }
private:
	default_random_engine re;
	uniform_int_distribution <> dist;
};

/**
*\ brief находит индексы первой пары соседних элементовс разными знаками
*\ param array массив состоящий из целых чисел
*\ param quantity количество элементов массива
*\ return индексы первой пары соседних элементов с разными знаками
*/
string index(const int* array, const int quantity);
/**
*\ brief находит количество элементов, которые делятся на заданое число N без остатка
*\ param array массив состоящий из целых чисел
*\ param quantity количество элементов массива
*\ return количетво элементов, которые делятся на заданное чисо N без остатка
*/
int quant(const int* array, const int quantity, int n);
/**
*\ brief функция ввода элементов многомерного массива, как случайными числами, так и с помощью клавиатуры по желанию пользователя
*\ param array массив состоящий из целых чисел
*\ param quantity количество элементов массива
*/
void enter1(int* array, const int quantity);
/**
*\ brief заменяет предпоследний элемент массива на максимальный по модулю
*\ param array массив из n целых чисел
*\ param quantity количество элементов массива
*\ return измененный массив
*/
void repl(const int* array, const int quantity);
/**
*\ brief Функция ввода элементов целого типа
* \ param message сообщение о том, что нужно ввести
* /
int enter_int(const string & message);
/**
*\ brief Функция ввода с клавиатуры массива целых чисел arrayа
*\ param array массив состоящий из целых чисел
*\ param quantity кол-во элементов массива
*/
void input_array(int* array, const int quantity);
/**
*\ brief Функция вывода элементов
*\ param array массив состоящий из целых чисел
*\ param quantity кол-во элементов массива
*/
void print_array(const int* array, const int quantity);
int main()
{
	const int quantity = 81;
	system("chcp 1251"); //вывод в консоль русского шрифта
	int n;
	cin » n;
	int* array = new int[quantity];
	enter1(array, quantity);

	cout « "количество тех элементов,знаения которых делятся на n без остатка " « quant(array, quantity, n) « "\n";
	cout « "индексы 1-ой пары элементов с разными знаками " « index(array, quantity) « "\n";
	cout « "массив,с заменённым предпоследним элементом на максимальный по модолю ";
	print_array(array, quantity);
	delete[] array;
}
int enter_int(const string& message)
{
	cout « message;
	int temp;
	cin » temp;
	return temp;
}
int quant(const int* array, const int quantity, int n)
{
	int s = 0;
	for (int i = 0; i < quantity; i++)
	{
		if ((array[i] % n) == 0)
		{
			s = s + 1;
		}
	}
	return s;
}
string index(const int* array, const int quantity)
{
	stringstream ind;
	for (int i = 0; i < (quantity - 1); i++)
	{
		if (array[i] * array[i + 1] < 0)
		{
			ind « to_string(i) « "(номер 1-го элемента пары) "«to_string(i + 1) « "(номер 2-го элемента пары) ";
			break;
		}
	}
	return ind.str();
}
void repl(int* array, const int quantity)
{
	int max = 0;
	for (int i = 0; i < quantity; i++)
	{
		if ((array[i] > array[i + 1]) && (abs(array[i]) > max))
		{
			max = array[i];
		}
	}
	array[quantity - 1] = max;
}
void enter1(int* array, const int quantity)
{
	enum input_selection { randomly = 0, ither };
	int temp;
	cout « "Введите randomly для заполнения массива случайными числами, иначе ither - "; std::cin » temp;
	if (temp == ither)
	{
		input_array(array, quantity);
	}
	else
	{
		if (temp == randomly)
		{
			const int range_min = -40;
			const int range_max = 40;
			Rand_int rnd{ range_min,range_max };
			for (int i = 0; i < quantity; i++)
			{
				array[i] = rnd();
			}
		}
	}
}
void print_array(const int* array, int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		cout «("array[") « i « "]=" « array[i] « "\n";
	}
}
void input_array(int* array, const int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		stringstream message;
		message « "Enter array
			[" « i « "] = ";
			array[i] = enter_int(message.str());
	}
}
