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
ll a, b;

void solve () {
	cin >> a >> b;
	ll neg = (a < 0 ? (b - a + 1) : 0);
	if (a <= 0 && b >= 0) cout << "Zero";
	else if (neg & 1) {cout << "Negative";}
	else cout << "Positive";
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cin >> tt;
	while (tt--) solve();
	respa;
}