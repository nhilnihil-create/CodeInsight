#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	int N; std::cin >> N;
	std::vector<int> a(N);
	for (auto& r : a) {
		int t; std::cin >> t;
		r = t - 1;
	}

	int count = 0;
	for (int i = 0; i < N; ++i)
		if (a[a[i]] == i)++count;

	std::cout << count / 2 << std::endl;

}