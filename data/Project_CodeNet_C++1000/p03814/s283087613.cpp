#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	std::string S; std::cin >> S;
	int a, z;
	for (int i = 0; i < S.size(); ++i) {
		if (S[i] == 'A') {
			a = i;
			break;
		}
	}
	for (int i = S.size() - 1; i >= 0; --i) {
		if (S[i] == 'Z') {
			z = i;
			break;
		}
	}
	std::cout << z - a + 1 << std::endl;

	return 0;
}