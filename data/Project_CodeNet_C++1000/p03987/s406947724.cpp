#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }

vector<int> a(200005);

struct segtree {
	int seg[800005];
	int segmin(int u, int v) { return a[u] <= a[v] ? u : v; }
	void build(int id, int l, int r) {
		if (l == r) { seg[id] = l; return; }
		int m = l + r >> 1;
		build(id * 2, l, m);
		build(id * 2 + 1, m + 1, r);
		seg[id] = segmin(seg[id * 2], seg[id * 2 + 1]);
	}
	int query(int id, int l, int r, int ql, int qr) {
		if (l == ql && r == qr) return seg[id];
		int m = l + r >> 1;
		if (qr <= m) return query(id * 2, l, m, ql, qr);
		else if (ql > m) return query(id * 2 + 1, m + 1, r, ql, qr);
		else return segmin(
				query(id * 2, l, m, ql, m),
				query(id * 2 + 1, m + 1, r, m + 1, qr));
	}
} seg;

int n;

ll solve(int l, int r) {
	if (l > r) return 0;
	int u = seg.query(1, 1, n, l, r);
	return solve(l, u - 1) + solve(u + 1, r) + 1ll * (u - l + 1) * (r - u + 1) * a[u];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	read(n);
	rep(i, 1, n + 1) {
		read(a[i]);
	}
	seg.build(1, 1, n);
	die(solve(1, n));
}
