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
	std::cout << std::endl;
}

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int value)
{
	for (int i = 0; i < actual_size; ++i)
	{
		if (i > actual_size)
		{
				std::cout << "Ошибка: вышли за границы массива!" << std::endl;
		}
	}

	if (logical_size + 1 == actual_size)
	{
		int* new_arr = new int[actual_size * 2]();
		actual_size *= 2;
		for (int i = 0; i < logical_size; ++i)
		{	
			new_arr[i] = arr[i];
		}
		new_arr[logical_size] = value;
		logical_size += 1;
		arr = new_arr;
		return arr;
	}
	else
	{
		arr[logical_size] = value;
		logical_size += 1;
		return arr;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int logical_size, actual_size;
	int value = 1;
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
		while (value != 0)
		{
			std::cout << "Введите элемент для добавления: ";
			std::cin >> value;

			int* result_arr = append_to_dynamic_array(arr, logical_size, actual_size, value);
			print_dynamic_array(result_arr, logical_size, actual_size);
		}

		delete[] arr;
	}
}