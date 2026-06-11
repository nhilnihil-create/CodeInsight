#include <iostream>

int main()
{
	int n;
	std::string s;
	std::cin >> n >> s;
	
	int max = 0;
	int x = 0;
	for (char c : s) {
		if (c == 'I') x++; else x--;
		if (x > max) max = x;
	}
	
	std::cout << max << std::endl;
	
	return 0;
}
