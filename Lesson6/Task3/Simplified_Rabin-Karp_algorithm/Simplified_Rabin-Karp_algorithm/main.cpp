#include <iostream>
#include <string>

int find_substring_light_rabin_karp(const char* s1, const char* s2)
{
	bool approach = true;
	for (int i = 0; i < strlen(s1); ++i)
	{
		for (int j = 0; j < strlen(s2); ++j)
		{
			if (s1[i + j] != s2[j])
			{
				approach = false;
				break;
			}
			else
			{
				approach = true;
			}

		}
		if (approach)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	std::string string;
	std::string substring;

	std::cout << "Enter the line in which the search will be performed: ";
	std::cin >> string;
	do
	{
		std::cout << "Enter the substring you want to find: ";
		std::cin >> substring;
		const char* c1 = string.c_str();
		const char* c2 = substring.c_str();

		int found = find_substring_light_rabin_karp(c1, c2);

		if (found != -1)
		{
			std::cout << "Substring " << substring << " found by index " << found << std::endl;
		}
		else
		{
			std::cout << "Substring " << substring << " not found" << std::endl;
		}
		
	} while (substring != "exit");
}