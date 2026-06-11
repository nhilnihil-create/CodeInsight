#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	long long A, B, C; std::cin >> A >> B >> C;
	if (A % 2 == 0 || B % 2 == 0 || C % 2 == 0)
		std::cout << 0 << std::endl;
	else
		std::cout << std::min({A * B, B * C, C * A}) << std::endl;
	
	return 0;
}