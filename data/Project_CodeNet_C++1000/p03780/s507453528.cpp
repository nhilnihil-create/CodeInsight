#include<iostream>
#include<algorithm>
#include<vector>
int N, K;
bool DP[5010][5010];
std::vector<int> A;
bool solve(int x) {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < K; j++) {
			DP[i][j] = false;
		}
	}
	DP[0][0] = true;
	/*for (int j = 0; j <= N; j++) {
		std::cout << "    " << j << std::endl;

		for (int i = K - A[x]; i < K; i++) {
			if (DP[j][i]) {
				std::cout << "   " << i << std::endl;
			}
		}
	}*/
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			if (DP[i][j]) DP[i + 1][j] = true;
			if (i == x) continue;
			if (j + A[i] < K && DP[i][j]) DP[i + 1][j + A[i]] = true;
		}
	}
	for (int i = K - A[x]; i < K; i++) {
		if (DP[N][i])return true;
	}
	return false;
}

int main() {
	std::cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int tmp;
		std::cin >> tmp;
		A.push_back(tmp);
	}
	std::sort(A.begin(), A.end());
	int lb = -1;
	int ub = N;
	while (ub - lb > 1) {
		int mid = (ub + lb) / 2;
		if (A[mid] >= K) {
			ub = mid;
			continue;
		}
		if (solve(mid)) {
			ub = mid;
		}
		else {
			lb = mid;
		}
	}
	std::cout << lb + 1 << std::endl;
	return 0;
}