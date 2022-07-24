#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	std::cout << "Динамический массив: ";
	for (int i = 0; i < actual_size; ++i)
	{
		if (i >= logical_size)
		{
			std::cout << "_ ";
			continue;
		}
		std::cout << arr[i] << " ";
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int logical_size, actual_size;
	std::cout << "Введите фактический размер массива: ";
	std::cin >> actual_size;
	std::cout << "Введите логический размер массива: ";
	std::cin >> logical_size;

	if (logical_size > actual_size)
	{
		std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
	}
	else
	{
		int* arr = new int[actual_size]();

		for (int i = 0; i < logical_size; ++i)
		{
			int value = 0;
			std::cout << "arr[" << i << "]: ";
			std::cin >> value;
			arr[i] = value;
		}

		print_dynamic_array(arr, logical_size, actual_size);
		delete[] arr;
	}
}