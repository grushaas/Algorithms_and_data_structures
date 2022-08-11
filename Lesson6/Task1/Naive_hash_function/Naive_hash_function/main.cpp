#include <iostream>
#include <string>

int simple_string_hash(const char* s)
{
	int ans = 0;
	for (int i = 0; i < strlen(s); ++i)
	{
		int c = s[i];
		ans += c;
	}
	return ans;
}

int main()
{
	std::string string;
	do
	{
		std::cout << "Enter the line: ";
		std::cin >> string;
		const char* c = string.c_str();

		std::cout << "Naive hash of a string " << string << " = " << simple_string_hash(c) << std::endl;
	} while (string != "exit");
}