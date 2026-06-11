#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
template <typename T> using ord_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 123;
ll n, m, a[N], f[3][N];

void upd(int c, int x, ll y) {
	for (; x < m; x |= (x + 1))
		f[c][x] += y;
}

ll get(int c, int x) {
	ll res = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		res += f[c][x];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i]--;
	for (int i = 1; i <= n; i++) {
		if (a[i] < a[i - 1]) {
			ll need = (a[i - 1] - a[i] + m - 1) / m;
			a[i] += need * m;
		}
		if (i > 1) {
			int l = (a[i - 1] + 1) % m;
			int r = a[i] % m;
			int c = (a[i - 1] + 1) / m;
			if (l > r) {
				upd(0, l, a[i - 1] + 1);
				upd(1, l, 1);
				upd(2, l, c * m);
				l = 0;
				c++;
			}
			upd(0, l, a[i - 1] + 1);
			upd(1, l, 1);
			upd(2, l, c * m);
			upd(0, r + 1, -(a[i - 1] + 1));
			upd(1, r + 1, -1);
			upd(2, r + 1, -c * m);
		}
	}
	ll res = 1e18;
	for (int i = 0; i < m; i++) {
		ll s = get(0, i);
		ll num = get(1, i);
		ll c = get(2, i);
		res = min(res, (a[n] - a[1]) - (c + num * i - s));
	}
	cout << res;
}
