#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int m = N / 2;
	vector<int> B(N);
	B[N] = { 0 };
	for (int i = 0; i < N; i++) {
		B[A[i]]++;
	}
	bool flag = true;
	if (N % 2 == 0) {
		for (int i = 0; i < m; i++) {
			if (B[2 * i+1] != 2) {
				flag = false;
			}
		}
	}
	else {
		for (int i = 1; i <= m; i++) {
			if (B[0] != 1) {
				flag = false;
			}
			if (B[2 * i] != 2) {
				flag = false;
			}
		}
	}
		if (flag == false) {
			cout << 0;
		}
		else {
			long long res = 1;
			for (int i = 0; i < m; i++) {
				res = res * 2 % 1000000007;
			}
			cout << res;
		}
		return 0;
}