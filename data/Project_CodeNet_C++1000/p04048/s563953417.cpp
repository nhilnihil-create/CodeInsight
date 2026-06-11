#include<bits/stdc++.h>
#include <array>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
using LL = long long;
using ULL = unsigned long long;

ULL solve2(ULL a, ULL b, ULL c, ULL d, ULL e, ULL f) {
	if (a == 0 || f == 0) return 0;
	if (c >= a) {
		if (f > a) {
			ULL t = min(c, f) / a;
			return a * t * 2 + solve2(a, b, c - a * t, d, e, f - a * t);
		}
		return a + solve2(a, 0, f, e, d, c - a);
	}
	return c + solve2(c, 0, a, 0, c, d - f);
}

void solve() {
	ULL n, x; cin >> n >> x;
	ULL ans = x;
	ans += solve2(n - x, 0, n, 0, n - x, x);
	cout << ans << endl;
}

int main() {

	solve();

	return 0;
}
