#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
int main() {
	
	int n;
	cin >> n;
	ll ans = 1;
	map<int, ll> cnt;
	for (int i=1; i<=n; i++) {
		int val = i;
		while (val % 2 == 0) {
			cnt[2]++;
			val >>= 1;
		}
		for (int j=3; j*j<=val; j+=2) {
			while (val % j == 0) {
				cnt[j]++;
				val /= j;
			}
		}
		if (val != 1)
			cnt[val]++;
	}
	
	for (auto& e:cnt) {
		ans = ((ans % MOD) * ((e.second + 1) % MOD)) % MOD;
	}
	
	cout << ans << '\n';
	
	
	return 0;
}
