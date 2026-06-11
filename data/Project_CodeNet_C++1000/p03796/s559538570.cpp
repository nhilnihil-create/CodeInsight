#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)
typedef long long ll;

using namespace std;

const ll MOD = 1e9 + 7;

int main(void) {
	int N; cin >> N;
	ll ans = 1;

	for (int i = 1; i <= N; i++) {
		ans = (ans * i) % MOD;
	}

	cout << ans << endl;

	return 0;
}