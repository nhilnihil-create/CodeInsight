// Bismillahirrahmanirrahim
// by Batrrr Tolkynbayev
#include <bits/stdc++.h>
// skripi krasava
#define respa return 0
#define all(x) x.begin(), x.end()
#define sz size
#define pb push_back
#define eb emplace_back
#define forn(i, x, n) for(int i = x; i <= n; ++i)
#define forr(i, n, x) for(int i = n; i >= x; --i)

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 3e5 + 17, M = N << 2, mod = 1e9 + 7; 

ll tt = 1, n, c, k, t[N], ct, res, that;

void solve () {
	cin >> n >> c >> k;
	forn(i, 1, n) cin >> t[i];
	sort(t + 1, t + n + 1);
	forn(i, 1, n) {
		if (i == 1 || ct == c || that + k < t[i]) {
			that = t[i];
			ct = 0;
			++res;
		}
		++ct;
	}
	cout << res;
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cin >> tt;
	while (tt--) solve();
	respa;
}