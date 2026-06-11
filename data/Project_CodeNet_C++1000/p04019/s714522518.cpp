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
string travel;

void solve () {
	cin >> travel;
	bool n = 0, s = 0, e = 0, w = 0;
	for (int i = 0; i < travel.sz(); i++) {
		n = max(n, (travel[i] == 'N'));
		s = max(s, (travel[i] == 'S'));
		e = max(e, (travel[i] == 'E'));
		w = max(w, (travel[i] == 'W'));
	}
	if (!((n ^ s) + (e ^ w))) cout << "Yes";
	else cout << "No";
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cin >> tt;
	while (tt--) solve();
	respa;
}