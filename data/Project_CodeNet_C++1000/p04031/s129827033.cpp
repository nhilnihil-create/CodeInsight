#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	int ans = 1e9;
	for (int i = -100; i <= 100; ++i) {
		int subans = 0;
		for (int j = 0; j < N; ++j) {
			subans += (A[j] - i)*(A[j] - i);
		}
		ans = min(ans, subans);
	}
	cout << ans << endl;
	return 0;
}