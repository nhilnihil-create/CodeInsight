#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int K, S; cin >> K >> S;

	ll ans = 0;
	rep(x, K+1)rep(y, K+1) {
		int z = S - x - y;
		if (0 <= z && z <= K)ans++;
	}

	cout << ans << endl;

	return 0;
}