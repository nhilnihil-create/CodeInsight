#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

int main(){
	intt N; std::cin >> N;
	std::vector<intt> A(N);
	for (int i = 0; i < N; ++i)
		std::cin >> A[i];

	intt i = 0;
	intt ans = 0;
	while (true) {
		if (i == N)
			break;
		intt incre = i;
		intt decre = i;
		while (incre < N - 1 && A[incre] <= A[incre + 1])
			++incre;
		while (decre < N - 1 && A[decre] >= A[decre + 1])
			++decre;
		i = std::max(incre, decre) + 1;
		++ans;
	}
	std::cout << ans << std::endl;

	return 0;
}