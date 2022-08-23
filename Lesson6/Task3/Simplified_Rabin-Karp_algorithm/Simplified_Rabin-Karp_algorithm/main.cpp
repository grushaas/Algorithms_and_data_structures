#include <iostream>
#include <string>

int hInit(int strLen)
{
	int d = 53;
	int p = 1000;
	int h = 1;

	for (int i = 1; i < strLen; i++)
	{
		h = (h * d) % p;
	}

	return h;
}

int ringHash(const char* str, int strLen, int prevHash, int* h)
{
	int d = 53;
	int p = 1000;

	if (*h == 0)
	{
		*h = hInit(strLen);
	}

	if (prevHash == 0)
	{
		for (int i = 0; i < strLen; i++)
		{
			prevHash += (d * prevHash + (int)str[i]) % p;
		}
		if (prevHash < 0)
		{
			prevHash += p;
		}

		return prevHash;
	}
	else
	{
		int hash = (d * (prevHash - (int)str[0] * (*h)) + (int)str[strLen]) % p;
		if (hash < 0)
		{
			hash += p;
		}

		return hash;
	}
}

int RabinKarpSearch(const char* text, const char* str)
{
	int strLen = strlen(str);
	int textLen = strlen(text);
	int h = 0;

	int strHash = ringHash(str, strLen, 0, &h);
	int textHash = ringHash(text, strLen, 0, &h);

	for (int k = 0; k <= (textLen); k++)
	{
		if (strHash == textHash)
		{
			for (int i = 0; (i < strLen) && (str[i] == text[k + i]); i++)
			{
				if (i == (strLen - 1))
				{
					return k;
				}
			}
		}

		textHash = ringHash(&text[k], strLen, textHash, &h);
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

		int found = RabinKarpSearch(s1, s2);

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