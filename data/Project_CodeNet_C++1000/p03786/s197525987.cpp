#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	vector<ll> acc(N);
	acc[0] = a[0];
	for (int i = 1; i < N; ++i)
		acc[i] = acc[i - 1] + a[i];
	for (int i = N - 2; i >= 0; --i) {
		if (a[i + 1] > acc[i] * 2) {
			cout << (N - 1 - i) << endl;
			return 0;
		}
	}
	cout << N << endl;
	return 0;
}