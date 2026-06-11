// Bismillahirrahmanirrahim
// by Batrrr Tolkynbayev
#include <bits/stdc++.h>
// skripi krasava
#define respa return 0
#define all(x) x.begin(), x.end()
#define sz size
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 2e5 + 17, M = N << 2, mod = 1e9 + 7; 

int tt = 1, n;
ll res, bal, a[N], b[N], d[N];

void solve () {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		d[i] = (a[i] + b[i] - 1) / b[i] * b[i] - a[i];
	}
	for (int i = n; i >= 1; --i) {
		if (d[i] < d[i + 1]) d[i] += ((d[i + 1] - d[i] + b[i] - 1) / b[i]) * b[i];
	}
	for (int i = n; i >= 1; --i) {
		d[i] -= bal;
		res += d[i];
		bal += d[i];
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