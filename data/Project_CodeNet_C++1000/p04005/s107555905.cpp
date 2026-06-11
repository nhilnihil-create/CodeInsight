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

int tt = 1;
ll a, b, c;

void solve () {
	cin >> a >> b >> c;
	if (a % 2 + b % 2 + c % 2 != 3) cout << 0;
	else cout << min(a * b, min(b * c, a * c));
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cin >> tt;
	while (tt--) solve();
	respa;
}