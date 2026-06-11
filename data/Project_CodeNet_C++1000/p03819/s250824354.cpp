#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> T;

const int DEPTH = 17;
class SegTree {
public:
	int A[1 << (DEPTH + 1)];
	SegTree() { for (int i = 0; i < (1 << (DEPTH + 1)); i++) A[i] = 0; }
	void add(int l, int r, int v, int a = 0, int b = (1 << DEPTH), int id = 0) {
		if (a >= r || b <= l) return;
		if (l <= a && b <= r) { A[id] += v; return; }
		add(l, r, v, a, a + (b - a) / 2, id * 2 + 1);
		add(l, r, v, a + (b - a) / 2, b, id * 2 + 2);
	}
	int getValue(int pos) {
		pos += (1 << DEPTH) - 1;
		int ret = A[pos];
		while (pos > 0) {
			pos = (pos - 1) / 2;
			ret += A[pos];
		}
		return ret;
	}
};

int n, m;
vector<T> kukan; int kid = 0;
SegTree seg;

signed main() {
	int i, j;
	
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		kukan.push_back(T(r - l + 1, l, r));
	}
	sort(kukan.begin(), kukan.end());
	
	for (i = 1; i <= m; i++) {
		int cnt = 0;
		for (j = i; j <= m; j += i) {
			cnt += seg.getValue(j);
		}
		cout << cnt + (n - kid) << endl;
		
		for (; kid < n && get<0>(kukan[kid]) <= i; kid++) {
			int l = get<1>(kukan[kid]);
			int r = get<2>(kukan[kid]);
			seg.add(l, r + 1, 1);
		}
	}
	
	return 0;
}