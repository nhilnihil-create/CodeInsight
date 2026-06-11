#include <bits/stdc++.h>

#define fs first
#define sc second
#define mp make_pair
#define eb emplace_back
#define sz(s) ((int) s.size())
#define all(s) s.begin(), s.end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef unsigned long long ull;

const ll linf = (ll) 1e18;

const int A = 26;
const int L = 17;
const int B = 315;
const int N = (int) 1e5;
const int inf = (int) 1e9;
const int mod = (int) 1e9 + 7;

const int di[] = {-1, +0, +1, +0};
const int dj[] = {+0, +1, +0, -1};

const ull pr = 31;
const ull hmod = (ull) 1e9 + 7;

const double pi = acos(-1.0);
const double eps = 1e-11;

inline void init() {
	
}
inline void solve() {
	int n, m; cin >> n >> m;
	ll sx = 0;
	ll px = 0;
	for (int i = 0; i < n; i++) {
		ll x; cin >> x;
		px += x * i - sx; px += mod; px %= mod;
		sx += x; sx += mod; sx %= mod;
	}		
	ll sy = 0;
	ll py = 0;
	for (int i = 0; i < m; i++) {
		ll y; cin >> y;
		py += y * i - sy; py += mod; py %= mod;
		sy += y; sy += mod; sy %= mod;
	}		
	cout << px * py % mod;

}
int main() {
	#ifdef LOCAL
		#define name ""
		freopen(name".in", "r", stdin);
		freopen(name".out", "w", stdout);
	#endif
	int tests = 1;
	while (tests--) {
		init();
		solve();
	}
	return 0;
}