#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>

int main() {
	int N=0;
	
	std::cin >>N;

	int total_candy=0;

	for(int i = 0; i <N+1 ; i++) {
	
	total_candy=i+total_candy;

	}
	std::cout << total_candy << std::endl;

	return 0;
}