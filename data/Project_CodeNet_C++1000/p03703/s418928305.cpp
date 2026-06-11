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
	int n; cin >> n;
	int64_t k; cin >> k;
	vector<int64_t> a(n + 1);
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		a[i] -= k;
		a[i] += a[i - 1];
	}
	vector<int64_t> mp = a;
	sort(mp.begin(), mp.end());
	mp.erase(unique(mp.begin(), mp.end()), mp.end());
	int vn = mp.size();
	vector<int64_t> idx(n + 1);
	for(int i = 0; i < n + 1; ++i) {
		idx[i] = lower_bound(mp.begin(), mp.end(), a[i]) - mp.begin();
	}
	SegmentTree<int64_t> seg(vn, 0, [](int64_t lhs, int64_t rhs) {
		return lhs + rhs;
	});
	int64_t ans = 0;
	for(int i = n; i >= 0; --i) {
		ans += seg.get(idx[i], vn);
		seg.replace(idx[i], seg.get(idx[i], idx[i] + 1) + 1);
	}
	cout << ans << '\n';
	return 0;
}