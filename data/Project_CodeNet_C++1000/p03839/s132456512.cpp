#include<bits/stdc++.h>
#include <array>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
using LL = long long;
using ULL = unsigned long long;

void solve() {
	int n; cin >> n;
	int k; cin >> k;
	LL a[100000]; rep(i, n) cin >> a[i];
	LL as[100001]; as[0] = 0;
	LL as2[100001]; as[0] = 0;
	rep(i, n) as[i + 1] = as[i] + a[i];
	rep(i, n) as2[i + 1] = as2[i] + max(0ll, a[i]);

	LL ans = 0;
	for (int i = k; i <= n; i++) {
		LL l = as2[n] - as2[i] + as2[i - k];
		LL B = as[i] - as[i - k];
		ans = max(ans, l + B);
		ans = max(ans, l);
	}

	cout << ans << endl;
}

int main() {

	solve();

	return 0;
}
