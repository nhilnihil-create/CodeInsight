#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;

ll mfact(ll a) {
	ll res = 1;
	for (ll i = 2; i <= a; i++) {
		res *= i;
		res %= mod;
	}
	return res;
}

int main(void) {
	ll N, M; cin >> N >> M;
	if (abs(N - M) >= 2) {
		cout << 0 << endl;
		return 0;
	}

	if (M > N)swap(N, M);
	ll fm = mfact(M);

	if (N == M) {
		cout << (2 * (fm * fm) % mod) % mod << endl;
	}
	else {
		ll fn = fm;
		for (ll i = M + 1; i <= N; i++)fn = (fn * i) % mod;
		cout << (fm * fn) % mod << endl;
	}

	return 0;
}