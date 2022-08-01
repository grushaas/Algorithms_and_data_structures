#include <iostream>

int parent_index(int* arr, int size, int i)
{
	int value = arr[(i - 1) / 2];
	return value;
}

void print_one_element(int* arr, int size, int i)
{
	if (i % 2)
	{
		std::cout << "left(" << parent_index(arr, size, i) << ") " << arr[i] << std::endl;
	}
	else
	{
		std::cout << "right(" << parent_index(arr, size, i) << ") " << arr[i] << std::endl;
	}
}


void print_pyramid(int* arr, int size)
{
	std::cout << "Пирамида:" << std::endl;

	for (int i = 0; i < size; ++i)
	{
		if (i == 0)
		{
			std::cout << "0 root " << arr[i] << std::endl;
		}
		else if (i > 0 && i < 3)
		{
			std::cout << "1 "; // Не могу додуматься как мне сделать так чтобы автоматически печатал правильную строку для тех или иных узлов
			print_one_element(arr, size, i);
		}
		else if (i > 2 && i < 7)
		{
			std::cout << "2 ";
			print_one_element(arr, size, i);
		}
		else if (i > 6 && i < 15)
		{
			std::cout << "3 ";
			print_one_element(arr, size, i);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int const size = 8;
	int arr[size] = { 94, 67, 18, 44, 55, 12, 6, 42 };

	std::cout << "Исходный массив: ";
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	print_pyramid(arr, size);
}