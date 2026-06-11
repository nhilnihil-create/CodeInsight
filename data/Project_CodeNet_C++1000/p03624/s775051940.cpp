#include <iostream>

int main()
{
	std::string s;
	std::cin >> s;
	
	char c = 'a';
	while (c <= 'z') {
		if (s.find(c) == std::string::npos) {
			break;
		}
		c++;
	}
	
	if (c > 'z') std::cout << "None" << std::endl;
	else std::cout << c << std::endl;
	
	return 0;
}
