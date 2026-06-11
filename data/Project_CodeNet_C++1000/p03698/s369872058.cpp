#include <iostream>

int main()
{
	std::string s;
	std::cin >> s;
	
	int alph[26] {};
	for (char c : s) alph[c - 'a']++;
	
	std::cout << (std::find_if(alph, alph + 26,
		[](int x) { return x > 1; }) == alph + 26 ?
		"yes" : "no") << std::endl;
	
	return 0;
}
