#include <bits/stdc++.h>

#define ll long long

using namespace std;

struct RSQRAQ {
	int n;
	vector<ll> dat, lazy;

	RSQRAQ() {}
	RSQRAQ(int n_) {
		n = 1; while (n < n_) n *= 2;
		dat.assign(n * 2, 0);
		lazy.assign(n * 2, 0);
	}

	void eval(int len, int k) {
		if (lazy[k] == 0) return;
		if (k * 2 + 1 < n * 2 - 1) {
			lazy[2 * k + 1] += lazy[k];
			lazy[2 * k + 2] += lazy[k];
		}
		dat[k] += lazy[k] * len;
		lazy[k] = 0;
	}

	// [a, b)
	ll update(int a, int b, ll x, int k, int l, int r) {
		eval(r - l, k);
		if (b <= l || r <= a) return dat[k];
		if (a <= l && r <= b) {
			lazy[k] += x;
			return dat[k] + lazy[k] * (r - l);
		}
		return dat[k] = update(a, b, x, 2 * k + 1, l, (l + r) / 2) + update(a, b, x, 2 * k + 2, (l + r) / 2, r);
	}
	ll update(int a, int b, ll x) { return update(a, b, x, 0, 0, n); }

	// [a, b)
	ll query(int a, int b, int k, int l, int r) {
		eval(r - l, k);
		if (b <= l || r <= a) return 0;
		if (a <= l && r <= b) return dat[k];
		ll vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
		ll vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
		return vl + vr;
	}
	ll query(int a, int b) { return query(a, b, 0, 0, n); }
};

signed main() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	RSQRAQ seg(m + 1);
	for (int i = 0; i < n - 1; ++i) {
		int b = (a[i + 1] - a[i] + m) % m;
		if (b == 1 || b == 0) continue;
		seg.update(max(0, a[i + 1] - b + 1), a[i + 1], 1LL);
		seg.update(a[i + 1], a[i + 1] + 1, -b + 1LL);
		if (a[i + 1] - b + m + 1 < m)
			seg.update(a[i + 1] - b + m + 1, m, 1LL);
	}
	vector<ll> times(m + 1, 0);
	{ // 1に設定したときの回数を求める
		ll res = 0;
		for (int i = 0; i < n - 1; ++i)
			res += min((a[i + 1] - a[i] + m) % m, (a[i + 1] - 1 + m) % m + 1);
		times[1] = res;
	}
	for (int i = 1; i < m; ++i) {
		times[i + 1] = times[i] - seg.query(i, i + 1);
	}
	ll ans = 100000000000000LL;
	for (int i = 1; i <= m; ++i)
		ans = min(ans, times[i]);
	cout << ans << endl;
	return 0;
}