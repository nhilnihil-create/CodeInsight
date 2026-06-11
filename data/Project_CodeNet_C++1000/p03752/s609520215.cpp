#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	int n, k;
	ll ans = 9999999999999;
	cin >> n >> k;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	for(int i = 0; i < 1<<(n - 1); i++) {
		if(k - 1 != __builtin_popcount(i)) continue;
		ll yen = 0, max = a[0] + 1;
		rep(j,n-1) {
			if(i>>j & 1) {
				if(max <= a[j + 1]) max = a[j + 1] + 1;
				else {
					yen += max - a[j + 1];
					max++;
				}
			}
			else if (max <= a[j + 1]) {
				yen = 999999999999;
				j = n - 2;
			}
		}
		ans = min(yen,ans);
	}

	cout << ans << endl;;
	return 0;
}