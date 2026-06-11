#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	ll N, M;
	cin >> N >> M;
	ll mod = 1e9+7;

	if (abs(N-M)>1) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 1;
	rep(i,N) {
		ans *= i+1;
		ans %= mod;
	}
	rep(i,M) {
		ans *= i+1;
		ans %= mod;
	}
	if (abs(N-M) == 0) {
		ans *= 2;
		ans %= mod;
	}
	cout << ans << endl;

	return 0;
}