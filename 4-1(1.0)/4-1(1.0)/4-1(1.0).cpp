#include <iostream>
#include <random>

using namespace std;
/**
*\brief Класс констант метода ввода
*/
enum class InputMethod
{
	random,
	manual
};
/**
*\brief Функция выполняет заданный блок других функций для повышения читабельности и сокращения кода
*\param array массив
*\param size размер Массива
*/
void BlockOfFunctions(int *array, const size_t size);
/**
*\brief Функция ищет индексы первой пары чисел в массиве, разных по знаку
*\param array массив
*\param size размер Массива
*\return Возвращает индекс второго элемента пары в случае успеха
*/
size_t FirstDiffPair(const int *array, const size_t size);
/**
*\brief Функция считает количество элементов в массиве, которые делятся на произвольное число без остатка
*\param array массив
*\param size размер Массива
*\return Возвращает количество элементов
*/
size_t ModNZero(int *array, const size_t size);
/**
*\brief Функция меняет предпоследний элемент в массиве на максиальный по модулю
*\param array массив
*\param size размер Массива
*/
void MaxAbs(int *array, const size_t size);
/**
*\brief Функция возвращает массив размера size, заполненный пользователем вручную
*\param size размер Массива
*\return Заполненный массив
*/
int *FillManualArray(const size_t size);
/**
*\brief Функция возвращает массив размера size, заполненный случайнвыми числами в заданном диапозоне
*\param size размер Массива
*\param minValue Нижний предел генерации чисел
*\param maxValue Верхний предел генерации чисел
*\return Заполненный массив
*/
int *FillRandomArray(const size_t size, const int minValue, const int maxValue);
/**
*\brief Функция выводит массив в консоль
*\param array массив
*\param size размер Массива
*/
void PrintArray(const int *array, const size_t size);
/**
*\brief Функция возвращает целочисленное число, введённое пользователем
*\param message Сообщение, выводимое в консоль
*\return Возвращает число, введённое пользователем
*/
int InputInt(const std::string &message);
/**
*\brief Точка входа в программу
*\return 0 в случае успеха
*/
int main()
{
	cout << "";
	size_t size = InputInt("How much numbers will be in your array?");
	cout << "What the lower and upper limits of values in array?\n";
	int minValue, maxValue;
	cin >> minValue >> maxValue;
	cout << "How do you prefer to fill your array?\n";
	cout << static_cast<int>(InputMethod::random) << " — random\n"
		 << static_cast<int>(InputMethod::manual) << " — manual";
	size_t choose = InputInt("");
	try
	{
		auto choosen = static_cast<InputMethod>(choose);
		switch (choosen)
		{
		case InputMethod::random:
		{
			int *array = FillRandomArray(size, minValue, maxValue);
			BlockOfFunctions(array, size);
			break;
		}
		case InputMethod::manual:
		{
			int *array = FillManualArray(size);
			BlockOfFunctions(array, size);
			break;
		}
		}
	}
	catch (out_of_range &)
	{
		return 1;
	}

	return 0;
}

int InputInt(const std::string &message)
{
	cout << message << std::endl;
	int input = -1;
	cin >> input;
	if (input < 0)
	{
		throw(out_of_range("Incorrect size"));
	}
	return input;
}

void PrintArray(const int *array, const size_t size)
{
	for (size_t index = 0; index < size; index++)
	{
		cout << array[index] << " ";
	}
	cout << endl;
}

int *FillRandomArray(const size_t size, const int minValue, const int maxValue)
{
	random_device randomly;
	mt19937 gen(randomly());
	uniform_int_distribution<> Uniform_int_distribution(minValue, maxValue);
	auto *array = new int[size];
	for (size_t index = 0; index < size; index++)
	{
		array[index] = Uniform_int_distribution(gen);
	}
	return array;
}

int *FillManualArray(const size_t size)
{
	int *array = new int[size];
	for (size_t index = 0; index < size; index++)
	{
		cin >> array[index];
	}
	return array;
}

void MaxAbs(int *array, const size_t size)
{
	size_t maxAbsIndex = 0;
	for (size_t index = 1; index < size; index++)
	{
		if (abs(array[index]) > abs(array[maxAbsIndex]))
		{
			maxAbsIndex = index;
		}
	}
	array[size - 2] = array[maxAbsIndex];
}

size_t ModNZero(int *array, const size_t size)
{
	size_t number = 0;
	int n = 0;
	cout << "Enter some number\n";
	while (n == 0)
	{
		cin >> n;
	}
	for (size_t index = 0; index < size; index++)
	{
		if (abs(array[index]) % n == 0)
		{
			number++;
		}
	}
	return number;
}

size_t FirstDiffPair(const int *array, const size_t size)
{
	for (size_t index = 0; index < size; index++)
	{
		if ((array[index] < 0 && array[index + 1] >= 0) || (array[index] >= 0 && array[index + 1] < 0))
		{
			return index + 1;
		}
	}
	return 0;
}

void BlockOfFunctions(int *array, const size_t size)
{
	PrintArray(array, size);
	MaxAbs(array, size);
	int number = ModNZero(array, size);
	cout << "Count of numbers, which reminder of division by N == 0 — " << number << endl;
	;
	if (FirstDiffPair(array, size) != 0)
	{
		cout << "Idexes of first different signs element in array is " << FirstDiffPair(array, size) - 1 << ", " << FirstDiffPair(array, size) << endl;
		PrintArray(array, size);
	}
}
