#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

constexpr ll mod = 1000000007LL;

int main(void){
	int N; cin >> N;
	vector<int> T(N), A(N);
	for (auto& ti : T) cin >> ti;
	for (auto& ai : A) cin >> ai;
	if (T[N - 1] != A[0]){
		cout << 0 << endl;
		return 0;
	}
	vector<int> d(N, 0);
	d[0] = T[0];
	d[N - 1] = A[N - 1];
	for (int i = 1; i < N; ++i){
		if (T[i] > T[i - 1] && d[i] == 0) d[i] = T[i];
		else if (T[i] > T[i - 1] && d[i] != T[i]){
			cout << 0 << endl;
			return 0;
		}
	}
	for (int i = 0; i < N - 1; ++i){
		if (A[i] > A[i + 1] && d[i] == 0)
			d[i] = A[i];
		else if (A[i] > A[i + 1] && d[i] != A[i]){
			cout << 0 << endl;
			return 0;
		}
	}
	for (int i = 0; i < N; ++i){
		if (d[i] > T[i] || d[i] > A[i]){
			cout << 0 << endl;
			return 0;
		}
	}
	ll res = 1;
	for (int i = 0; i < N; ++i)
		if (d[i] == 0)
			res = (res * min(A[i], T[i])) % mod;
	cout << res << endl;
	return 0;
}
