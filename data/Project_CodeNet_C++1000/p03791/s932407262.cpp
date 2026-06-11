#include <bits/stdc++.h>

using namespace std;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
typedef long long ll;

const ll mod = 1e9 + 7, ma1 = 8, ma = 256 * 1024;

ll n, ans = 1, seg[2 * ma];
vector<int> x;

ll get_min(int l, int r) {
	if (l > r) re 1000000LL;
	if (l % 2)
		re min(seg[l], get_min(l + 1, r));
	if (r % 2 == 0)
		re min(seg[r], get_min(l, r - 1));
	re get_min(l / 2, r / 2);
}

bool ok(ll mid, int i) {
	ll c = ll(get_min(mid + ma, i + ma - 1)) + 2LL * mid;
	if (c > 0)
		re true;
	re false;
}

int main() {
	iostream::sync_with_stdio(0);
	//freopen("a.in", "r", stdin);
	cin >> n;
	x.resize(n);
	forn (i, n) {
		cin >> x[i];
		seg[i + ma] = x[i] - 2LL * i;
	}
	//ll k = 1LL * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12;
	/*forn (i, 13)
		k = (k * ll(i + 1)) % mod;*/
	//cout << k % mod << "\n";
	for (int i = ma - 1; i; i--)
		seg[i] = min(seg[2 * i], seg[2 * i + 1]);
	forn (i, n) {
		int l = -1, r = i;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			if (ok(mid, i))
				r = mid;
			else 
				l = mid;
		}
		ans = (ans * ll(i - l)) % mod;
		//cout << i - l << "\n";
	}
	cout << ans;
}