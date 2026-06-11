// IOI 2021
 
#include <bits/stdc++.h>
using namespace std;

#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9, MOD = 1e6 + 7;
 
/////////////////////////////////////////////////////////////////////
 
const int N = 1e5 + 5, LOG = 20;

int n, l, X[N], PAR[N][LOG];

int main() {
 
	sync;

	cin >> n;
	for (int i = 0; i < n; i++) cin >> X[i];
	cin >> l;
	for (int i = 0; i < n; i++) PAR[i][0] = upper_bound(X, X + n, X[i] + l) - X - 1;
	for (int pw = 1; pw < LOG; pw++) for (int i = 0; i < n; i++) PAR[i][pw] = PAR[PAR[i][pw - 1]][pw - 1];
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r; l--, r--;
		if (l > r) swap(l, r);
		int ans = 0;
		for (int pw = LOG - 1; pw >= 0; pw--) if (PAR[l][pw] < r) l = PAR[l][pw], ans += (1 << pw);
		cout << ans + 1 << endl;
	}

	return 0;
}
