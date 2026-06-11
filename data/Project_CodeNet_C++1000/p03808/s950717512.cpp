#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, A[100000], SUM = 0, X;
	cin >> N;
	X = N * (N + 1) / 2;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		SUM += A[i];
	}
	if (SUM % X != 0) {
		cout << "NO";
		return 0;
	}
	long long COUNT = SUM / X;
	for (int i = 0; i < N; i++) {
		long long S = A[(i - 1 + N) % N] - A[i];
		if ((S + COUNT) % N != 0 || (S + COUNT) / N < 0) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}