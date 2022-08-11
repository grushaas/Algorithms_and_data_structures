#include <iostream>
#include <string>
#include <cstdint>

//Функция возведения в степень
std::int_fast64_t powint(int base, int exp)
{
	std::int_fast64_t result{ 1 };
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}

int real_string_hash(const char* s, int p, int n)
{
	int ans = 0;
	for (int i = 0; i < strlen(s); ++i)
	{
		int c = s[i];
		ans += c * powint(p, i);
	}
	return ans % n;
}


int main()
{
	int p, n;
	std::string string;

	std::cout << "Enter p: ";
	std::cin >> p;
	std::cout << "Enter n: ";
	std::cin >> n;
	do
	{
		std::cout << "Enter the line: ";
		std::cin >> string;
		const char* c = string.c_str();

		std::cout << "Hash of the string " << string << " = " << real_string_hash(c, p, n) << std::endl;
	} while (string != "exit");
}