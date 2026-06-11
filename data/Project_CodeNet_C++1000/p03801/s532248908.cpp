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
int n, a[N], p[N], b[N];
ll f[2][N], t, cur, ans[N];

void upd(int c, int x, ll y) {
	for (; x <= n; x |= (x + 1))
		f[c][x] += y;
}

ll get(int c, int x) {
	ll res = 0;
	for (; x >= 0; x = (x & (x + 1)) - 1)
		res += f[c][x];
	return res;
}

void solve(int pos, int mx) {
	if (pos == 1) {
		ans[pos] = t - cur;
		return;
	}
	int to = p[pos - 1];
	for (int i = pos; i > to; i--)
		upd(0, b[i], 1), upd(1, b[i], a[i]);
	ll num = get(0, mx) - get(0, b[to]);
	ans[pos] = (get(1, mx) - get(1, b[to])) - a[to] * num;
	upd(0, b[to], num);
	upd(1, b[to], num * a[to]);
	cur += ans[pos];
	solve(to, b[to]);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	vector <int> v;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		t += a[i];
		v.pb(a[i]);
		p[i] = p[i - 1];
		if (a[i] > a[p[i]])
			p[i] = i;
	}
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	for (int i = 1; i <= n; i++) b[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
	for (int i = n; i > p[n]; i--)
		upd(0, b[i], 1), upd(1, b[i], a[i]);
	solve(p[n], b[p[n]]);
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}
