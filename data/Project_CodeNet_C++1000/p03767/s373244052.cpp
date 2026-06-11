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

ll tt = 1, n, ct, res, a[N];
bool u[N];

void solve () {
	cin >> n;
	forn(i, 1, 3 * n) cin >> a[i];
	sort(a + 1, a + 3 * n + 1);
	ll i = 3 * n;
	while (i > 0) {
		if (u[i]) {
			--i; 
			continue;
		}
		u[i] = u[i - 1] = u[++ct] = true;
		res += a[i - 1]; --i;
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