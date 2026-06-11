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
#include <numeric>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cmath>

using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)(n);++i)
#define rep1(i, n) for (int i=1;i<=(int)(n);++i)
#define rrep(i, n) for (int i=(int)(n)-1;i>=0;--i)
#define rrep1(i, n) for (int i=(int)(n);i>=1;--i)
#define range(i, l, r) for (int i=l;i<(int)(r);++i)
#define rrange(i, l, r) for (int i=(int)(r)-1;i>=l;--i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using vi=vector<int>;
using pii=pair<int, int>;
using vpii=vector<pii>;
using ll=long long;

constexpr int TEN(int n){return n==0?1:10*TEN(n-1);}
template<typename T>bool chmin(T&a,T b){return a>b?(a=b,1):0;}
template<typename T>bool chmax(T&a,T b){return a<b?(a=b,1):0;}
int read(){int a;scanf("%lld",&a);return a;}

const long double pi = acos(-1);
constexpr int inf = 3*TEN(18) + 10;

struct SegTree { // 区間min,max
	int n;
	vector<int> Max;
	vector<int> Min;
	void init(int n_) {
		n = 1;
		while (n < n_) n *= 2;
		Max.resize(2 * n);
		Min.resize(2 * n);
		for (int i = 0; i < 2 * n - 1; ++i) {
			Max[i] = -inf;
			Min[i] = inf;
		}
	}
	void update(int idx, int val) {
		idx += n - 1;
		Min[idx] = val;
		Max[idx] = val;
		while (idx > 0) {
			idx = (idx - 1) / 2;
			Min[idx] = min(Min[idx * 2 + 1], Min[idx * 2 + 2]);
			Max[idx] = max(Max[idx * 2 + 1], Max[idx * 2 + 2]);
		}
	}
	int get_min(int a, int b, int k = 0, int l = 0, int r = -1) { // [a, b)のmin
		if (r == -1) r = n;
		if (r <= a || b <= l) return inf;
		if (a <= l && r <= b) return Min[k];
		int vl = get_min(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = get_min(a, b, k * 2 + 2, (l + r) / 2, r);
		return min(vl, vr);
	}
	int get_max(int a, int b, int k = 0, int l = 0, int r = -1) { // [a, b)のmax
		if (r == -1) r = n;
		if (r <= a || b <= l) return -inf;
		if (a <= l && r <= b) return Max[k];
		int vl = get_max(a, b, k * 2 + 1, l, (l + r) / 2);
		int vr = get_max(a, b, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
};

int N;
int a[200010], idx[200010];
SegTree st;

signed main()
{
	cin >> N;
	st.init(N + 1);

	rep(i, N) {
		cin >> a[i];
		--a[i];
		idx[a[i]] = i;
	}

	int ans = 0;

	range(i, 0, N) {
		int l = st.get_max(0, idx[i]) + 1;
		int r = st.get_min(idx[i], N) - 1;

		if (l < 0) l = 0;
		if (r > N) r = N - 1;

		int lenl = idx[i] - l + 1;
		int lenr = r - idx[i] + 1;

		ans += (i + 1) * lenl * lenr;

		st.update(idx[i], idx[i]);
	}

	cout << ans << endl;
}

