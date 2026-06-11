#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	std::string S; std::cin >> S;
	bool n = 0;
	bool s = 0;
	bool e = 0;
	bool w = 0;
	for (auto& r : S) {
		if (r == 'N')
			n = 1;
		if (r == 'S')
			s = 1;
		if (r == 'E')
			e = 1;
		if (r == 'W')
			w = 1;
	}
	if (n == s && e == w)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

}