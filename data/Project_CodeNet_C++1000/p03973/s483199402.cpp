#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	ll res = 0; int nx = 1;
	for (int i = 0; i < N; ++i) {
		if (A[i] % nx) {
			res += A[i] / nx;
			A[i] -= A[i] / nx * nx;
		}
		else if (A[i] > nx) {
			res += A[i] / nx - 1LL;
			A[i] = 1;
		}
		if (A[i] >= nx) ++nx;
	}
	cout << res << endl;
	return 0;
}