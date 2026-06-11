#include <bits/stdc++.h>
using namespace std;

template<class T>
struct SegmentTree {
	using F = function<T(T, T)>;
	const T init;
	const F f;
	int sz;
	vector<T> seg;
	SegmentTree(int n, const T init, const F f) :
		init(init),
		f(f)
		{
			sz = 1;
			while(sz < n) sz <<= 1;
			seg.resize(sz << 1, init);
		}
	void update(int id) {
		while(id >>= 1) {
			seg[id] = f(seg[2 * id], seg[2 * id + 1]);
		}
	}
	void replace(int id, T x){
		id += sz;
		seg[id] = x;
		update(id);
	}
	// [l,r)
	T get(int l, int r){
		T L = init, R = init;
		for(l += sz, r += sz; l < r; l >>= 1, r>>= 1) {
			if(l & 1) L = f(L, seg[l++]);
			if(r & 1) R = f(seg[--r], R);
		}
		return f(L, R);
	}
	void debug(){
		int i = 1;
		for(int r = 2; r <= 2 * sz; r <<= 1) {
			while(i < r) {
				cout << seg[i++] << " ";
			}
			cout << "\n";
		}
	}
};

int main() {
	int n, m; cin >> n >> m;
	pair<int, pair<int, int>> p[n];
	for(int i = 0; i < n; ++i) {
		int l, r; cin >> l >> r;
		p[i] = {r - l + 1, {l, r}};
	}
	sort(p, p + n);
	SegmentTree<int> seg(m + 2, 0, [](int lhs, int rhs){return lhs + rhs;});
	int now = 0;
	for(int d = 1; d <= m; ++d) {
		while(now < n) {
			if(d < p[now].first) break;
			int l, r; tie(l, r) = p[now].second;
			seg.replace(l, seg.get(l, l + 1) + 1);
			seg.replace(r + 1, seg.get(r + 1, r + 2) - 1);
			++now;
		}
		int ans = n - now;
		for(int dd = d; dd <= m; dd += d) {
			ans += seg.get(0, dd + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}