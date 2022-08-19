#include <iostream>
#include <string>

long long hash(const char* s)
{
	int P = 53;
	long long ans = 0;
	int mult = 1;
	for (int i = 0; i < strlen(s); ++i)
	{
		int c = s[i];
		ans += mult * c;
		mult = mult * P;
	}
	return ans;
}

int find_substring_light_rabin_karp(const char* s1, const char* s2)
{
	bool approach = true;
	long long s2_hash = hash(s2);
	long long h = 0;
	int size1 = strlen(s1);
	int size2 = strlen(s2);

	for (int i = 0; i < size1; ++i)
	{
		if (i == 0)
		{
			h = hash(&s1[size1 - 1]);
		}
		else
		{
			h -= s1[i - 1];
			h += s1[i + size1 - 1];
		}

		if (h != s2_hash)
		{
			approach = false;
		}
		else
		{
			for (int j = 0; j < size2; ++j)
			{
				if (s1[i + j] != s2[j])
				{
					approach = false;
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
		const char* s1 = string.c_str();
		const char* s2 = substring.c_str();

		int found = find_substring_light_rabin_karp(s1, s2);

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