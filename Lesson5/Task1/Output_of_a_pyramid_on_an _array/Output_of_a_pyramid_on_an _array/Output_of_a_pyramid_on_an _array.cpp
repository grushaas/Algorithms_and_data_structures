#include <iostream>
#include <cmath>

int parent_index(int* arr, int size, int i)
{
	int value = arr[(i - 1) / 2];
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
		std::cout << pyramid_level(arr, i) << " left(" << parent_index(arr, size, i) << ") " << arr[i] << std::endl;
	}
	else if (i == 0)
	{
		std::cout << pyramid_level(arr, i) << " root " << arr[i] << std::endl;
	}
	else
	{
		std::cout << pyramid_level(arr, i) << " right(" << parent_index(arr, size, i) << ") " << arr[i] << std::endl;
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