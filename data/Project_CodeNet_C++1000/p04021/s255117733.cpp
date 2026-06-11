#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		A[i] = { a, i % 2 };
	}

	sort(A.begin(), A.end());
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (i % 2 != A[i].second) { ++ans; }
	}
	cout << ans / 2 << endl;

	return 0;
}
