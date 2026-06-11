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
const int N = 2e5 + 17, M = N << 2, mod = 1e9 + 7; 

int tt = 1, n, a[N], odd;

void solve () {
	cin >> n;
	forn(i, 1, n) {
		cin >> a[i]; 
		odd += (a[i] & 1);
	}
	if (!(odd & 1)) cout << "YES";
	else cout << "NO";
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cin >> tt;
	while (tt--) solve();
	respa;
}