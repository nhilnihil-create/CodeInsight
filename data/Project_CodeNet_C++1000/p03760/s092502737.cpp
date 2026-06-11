#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	std::string O, E; std::cin >> O >> E;
	if (O.size() == E.size()) {
		for (int i = 0; i < O.size(); ++i)
			std::cout << O[i] << E[i];
		std::cout << std::endl;
	}
	else {
		for (int i = 0; i < E.size(); ++i)
			std::cout << O[i] << E[i];
		std::cout << O[O.size() - 1] << std::endl;
	}
	return 0;
}