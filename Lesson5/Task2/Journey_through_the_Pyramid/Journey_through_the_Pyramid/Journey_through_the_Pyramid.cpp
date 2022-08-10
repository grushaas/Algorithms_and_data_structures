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

int left_children(int i)
{
	if (i == 0)
	{
		int value = 1 + i;
		return value;
	}
	int value = 2 * i + 1;
	return value;
}

int right_children(int i)
{
	if (i == 0)
	{
		int value = 2 + i;
		return value;
	}
	int value = 2 * i + 2;
	return value;
}

bool is_there_a_left_child(int* arr, int size, int i)
{
	int value = left_children(i);
	for (int j = 0; j < size; ++j)
	{
		if (arr[value] == arr[j])
		{
			return true;
		}
	}
	return false;
}

bool is_there_a_right_child(int* arr, int size, int i)
{
	int value = right_children(i);
	for (int j = 0; j < size; ++j)
	{
		if (arr[value] == arr[j])
		{
			return true;
		}
	}
	return false;
}


bool is_there_a_parent(int* arr, int size, int i)
{
	int value = 0;

	if (i == 1)
	{
		value = i - 1;
	}
	else if (i == 2)
	{
		value = i - 2;
	}
	else
	{
		value = parent_index(arr, size, i);
	}

	for (int j = 0; j < size; ++j)
	{
		if (value == j)
		{
			return true;
		}
	}
	return false;
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
				if (i == 1)
				{
					i = parent_index(arr, size, i);
				}
				else if (i == 2)
				{
					i = parent_index(arr, size, i);
				}
				else
				{
					i = parent_index(arr, size, i);
				}
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
				i = left_children(i);
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
				i = right_children(i);
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