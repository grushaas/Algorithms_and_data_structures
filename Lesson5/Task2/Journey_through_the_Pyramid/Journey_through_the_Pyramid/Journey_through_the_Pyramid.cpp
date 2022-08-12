#include <iostream>
#include <cmath>
#include <string>

int parent_element(int* arr, int size, int i)
{
	int value = arr[(i - 1) / 2];
	return value;
}

int parent_index(int* arr, int size, int i)
{
	int value = (i - 1) / 2;
	return value;
}

int pyramid_level(int* arr, int i)
{
	return log2(i + 1);
}

void print_one_element(int* arr, int size, int i)
{
	if (i % 2)
	{
		std::cout << pyramid_level(arr, i) << " left(" << parent_element(arr, size, i) << ") " << arr[i] << std::endl;
	}
	else if (i == 0)
	{
		std::cout << pyramid_level(arr, i) << " root " << arr[i] << std::endl;
	}
	else
	{
		std::cout << pyramid_level(arr, i) << " right(" << parent_element(arr, size, i) << ") " << arr[i] << std::endl;
	}	
}

void print_pyramid(int* arr, int size)
{
	std::cout << "Пирамида:" << std::endl;

	for (int i = 0; i < size; ++i)
	{
		print_one_element(arr, size, i);
	}
}

int left_child_index(int i)
{
	return 2 * i + 1;
}

int right_child_index(int i)
{
	return 2 * i + 2;
}

bool is_there_a_left_child(int* arr, int size, int i)
{
	return left_child_index(i) < size;
}

bool is_there_a_right_child(int* arr, int size, int i)
{
	return right_child_index(i) < size;
}

void adventures(int* arr, int size)
{
	std::string command;
	int i = 0;

	do
	{
		std::cout << "Вы находитесь здесь: ";
		print_one_element(arr, size, i);
		
		std::cout << "Введите команду: ";
		std::cin >> command;

		if (command == "up")
		{
			if (i > 0)
			{
				std::cout << "OK" << std::endl;
				i = parent_index(arr, size, i);
			}
			else
			{
				std::cout << "Ошибка: Отсутствует родитель." << std::endl;
			}
		}
		else if (command == "left")
		{
			if (is_there_a_left_child(arr, size, i))
			{
				std::cout << "OK" << std::endl;
				i = left_child_index(i);
			}
			else
			{
				std::cout << "Ошибка: отсутствует левый ребенок!" << std::endl;
			}
		}
		else if (command == "right")
		{
			if (is_there_a_right_child(arr, size, i))
			{
				std::cout << "OK" << std::endl;
				i = right_child_index(i);
			}
			else
			{
				std::cout << "Ошибка: отсутствует правый ребенок!" << std::endl;
			}
		}
		else if(command == "exit")
		{
			std::cout << "Завершение работы программы." << std::endl;
		}
		else
		{
			std::cout << "Такой команды нет!" << std::endl;
		}


	} while (command != "exit");
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int const size = 6;
	int arr[size] = { 1, 3, 6, 5, 9, 8 };	

	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	print_pyramid(arr, size);
	adventures(arr, size);
}