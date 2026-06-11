#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	Int K;
	cin >> K;

	Int N = 50;
	vector<Int> ans(N, K / N);
	for (int i = 0; i < N; ++i) {
		if (i < N - K % N) {
			ans[i] += i;
		} else {
			ans[i] += i + 1;
		}
	}

	cout << N << endl;
	for (int i = 0; i < N; ++i) {
		cout << ans[i] << (i < N - 1 ? " " : "\n");
	}

	return 0;
}
