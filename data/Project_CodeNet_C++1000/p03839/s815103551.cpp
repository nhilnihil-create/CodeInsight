#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	vector<ll> acc(N + 1, 0), acc_pos(N + 1, 0);
	for (int i = 1; i <= N; ++i) {
		acc[i] = acc[i - 1] + a[i - 1];
		acc_pos[i] = acc_pos[i - 1] + (a[i - 1] > 0 ? a[i - 1] : 0);
	}
	ll res = 0;
	for (int i = 0; i <= N - K; ++i) {
		ll tmp = acc_pos[i];
		tmp += acc_pos[N] - acc_pos[i + K];
		ll lst = acc[i + K] - acc[i];
		if (lst > 0) tmp += lst;
		res = max(tmp, res);
	}
	cout << res << endl;
	return 0;
}