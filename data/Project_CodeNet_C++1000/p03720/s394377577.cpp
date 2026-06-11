#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	int N, M; std::cin >> N >> M;
	std::vector<int> A(M);
	std::vector<int> B(M);
	for (int i = 0; i < M; ++i)
		std::cin >> A[i] >> B[i];
	for (int num = 0; num < N; ++num) {
		int count = 0;
		for (int j{ 0 }; j < M; ++j) {
			if (A[j] == num + 1) ++count;
			if (B[j] == num + 1) ++count;
		}
		std::cout << count << std::endl;
	}

	return 0;
}