#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	/* 入力の受け取り */
	int N;
	cin >> N;
	vector<ll> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	/* 操作の回数を求める */
	ll remove = (ll)N * (N + 1) / 2; // 1回の操作で取り除く石の個数
	ll sum = accumulate(A.begin(), A.end(), 0LL); // 最初にある石の総個数
	if (sum % remove != 0) {
		cout << "NO" << endl;
		return 0;
	}
	ll rep = sum / remove; // 操作の回数

	/* 判定 */
	for (int i = 0; i < N; i++) {
		if (A[i] < rep) {
			cout << "NO" << endl;
			return 0;
		}
		A[i] %= N;
		ll sub = (ll)i * rep % N;
		A[i] = (A[i] - sub + N) % N;
	}
	bool f = true;
	for (int i = 0; i < N - 1; i++) f = f && (A[i] == A[i + 1]);
	cout << (f ? "YES" : "NO") << endl;

	return 0;
}