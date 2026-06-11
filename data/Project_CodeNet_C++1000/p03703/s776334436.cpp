#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>

using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)n;++i)
#define rep1(i, n) for (int i=1;i<=(int)n;++i)
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using vi=vector<int>;
using pii=pair<int, int>;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

constexpr int TEN(int n) { return n == 0 ? 1 : 10 * TEN(n - 1); }

const int mod = TEN(9) + 7;

int N, K;
int a[200010];
vi comp;

int idx(int v)
{
	return lower_bound(all(comp), v) - begin(comp);
}

struct SegTree { // 区間sum
	int n;
	vector<int> Sum;
	void init(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		Sum.resize(2 * n);
		for (int i = 0; i < 2 * n - 1; ++i) {
			Sum[i] = 0;
		}
	}
	void update(int idx, int val) {
		idx += n - 1;
		Sum[idx] += val;
		while (idx > 0) {
			idx = (idx - 1) / 2;
			Sum[idx] = Sum[idx * 2 + 1] + Sum[idx * 2 + 2];
		}
	}
	int get_sum(int a, int b, int k = 0, int l = 0, int r = -1) { // [a, b)のmax
		if (r == -1) r = n;
		if (r <= a || b <= l) return 0;
		if (a <= l && r <= b) return Sum[k];
		int vl = get_sum(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = get_sum(a, b, k * 2 + 2, (l + r) / 2, r);
		return (vl + vr);
	}
};

SegTree seg;

signed main()
{
	cin >> N >> K;
	
	seg.init(N * 2);

	int ans = 0;

	rep1(i, N) {
		cin >> a[i];
	}

	rep1(i, N) {
		a[i] += a[i - 1];
	}

	rep(i, N + 1) {
		a[i] -= K * i;
		comp.PB(a[i]);
	}

	sort(all(comp));
	comp.erase(unique(all(comp)), end(comp));

	seg.update(idx(0), 1);

	rep1(i, N) {
		ans += seg.get_sum(0, idx(a[i]) + 1);
		seg.update(idx(a[i]), 1);
	}

	cout << ans << endl;
}

