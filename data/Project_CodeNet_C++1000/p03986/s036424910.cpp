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

int tt = 1, n, p[N];
string s;

void solve () {
	cin >> s;
	n = s.sz();
	s = s + '#';
	int ct = 0, ct_t = 0;
	for (int i = n; i >= 0; --i) {
		ct_t += (s[i] == 'T');	                 
		if (s[i] == 'S' && (s[i + 1] == 'T' || ct_t)) {
			// cout << i << ' ' << i + 1 << '\n';
			++ct;
			--ct_t;
		}
	}
	cout << n - (ct << 1);
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cin >> tt;
	while (tt--) solve();
	respa;
}