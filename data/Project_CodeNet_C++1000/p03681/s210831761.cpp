#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	ll N, M;
	cin >> N >> M;
	if(abs(N - M) > 1) {
		cout << 0 << "\n";
		return 0;
	}
	ll ans = 2;
	if(N != M) ans--;
	while(N) {
		ans *= N;
		ans %= mod;
		N--;
	}
	while(M) {
		ans *= M;
		ans %= mod;
		M--;
	}
	cout << ans << "\n";
	return 0;
}
