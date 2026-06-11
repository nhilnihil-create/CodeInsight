#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
typedef pair<int, int> P;
class BiOp {
public:
	P operator()(const P &a, const P &b) const {
		if (a.first < b.first) {
			return b;
		}
		else if (a.first > b.first) {
			return a;
		}
		else if (a.first <= b.first) {
			return a;
		}
		else {
			return b;
		}
	}
};
template<typename T, typename BiOp>
struct SegmentTree {
	vector<T> data;
	T e;
	BiOp op;
	int size;
	SegmentTree(int n, T e, BiOp op) :e(e), op(op) {
		size = 1;
		while (size < n) size *= 2;
		data.resize(size * 2 - 1);
		for (int i = 0; i < size * 2 - 1; i++) data[i] = e;
	}
	void update(int k, T v) {
		k += size - 1;
		data[k] = v;
		while (k > 0) {
			k = (k - 1) / 2;
			data[k] = op(data[k * 2 + 1], data[k * 2 + 2]);
		}
	}
	T query(int a, int b, int k, int l, int r) const {
		if (b <= l || r <= a) return e;
		if (a <= l && r <= b) {
			return data[k];
		}
		return op(query(a, b, k * 2 + 1, l, (l + r) / 2), query(a, b, k * 2 + 2, (l + r) / 2, r));
	}
	T query(int a, int b) const {
		return query(a, b, 0, 0, size);
	}
	T get(int i) {
		return data[i + size - 1];
	}
};
ll ans[100001];
ll cnt[100001];
int a[100001];
int main() {
	int N;
	cin >> N;
	SegmentTree<P, BiOp> seg(N + 1, P(0, 1 << 30), BiOp());
	seg.update(0, P(0, 0));
	vector<int> h;
	h.push_back(0);
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		h.push_back(a[i]);
	}
	sort(h.begin(), h.end());
	h.erase(unique(h.begin(), h.end()), h.end());
	for (int i = 1; i <= N; i++) {
		a[i] = lower_bound(h.begin(), h.end(), a[i]) - h.begin();
		cnt[a[i]]++;
		seg.update(i, P(a[i], i));
	}
	P now = seg.query(1, N + 1);
	ll sum = 0;
	while (now.second > 0) {
		P nxt = seg.query(0, now.second);
		ll tmp = (h[now.first] - h[nxt.first])*sum;
		for (int i = now.first; i > nxt.first; i--) {
			sum += cnt[i];
			tmp += (h[i] - h[nxt.first]) * cnt[i];
		}
		ans[now.second] = tmp;
		now = nxt;
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << endl;
	}
}
