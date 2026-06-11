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
#define UNIQ(a) a.erase(unique(all(a)), end(a))

using vi=vector<int>;
using pii=pair<int, int>;
using vpii=vector<pii>;
using ll=long long;

constexpr int TEN(int n){return n==0?1:10*TEN(n-1);}
template<typename T>bool chmin(T&a,T b){return a>b?(a=b,1):0;}
template<typename T>bool chmax(T&a,T b){return a<b?(a=b,1):0;}
int read(){int a;scanf("%lld",&a);return a;}

const double pi = acos(-1);
constexpr int inf = 3*TEN(18) + 10;
constexpr int mod = TEN(9) + 7;

int N;
int mn[100010];
int counter[100010];

signed main()
{
	cin >> N;
	vi a(N);
	memset(mn, -1, sizeof mn);
	vi arr;
	rep(i, N) {
		cin >> a[i];
		arr.PB(a[i]);
	}
	arr.PB(0);
	sort(all(arr));
	UNIQ(arr);

	rep(i, N) {
		int idx = lower_bound(all(arr), a[i]) - begin(arr);
		counter[idx]++;
		if (mn[idx] == -1) mn[idx] = i;
	}

	vi ans(N);
	int minimum = inf;

	for (int i = (int)(arr.size()) - 1; i >= 1; --i) {
		chmin(minimum, mn[i]);
		ans[minimum] += counter[i] * (arr[i] - arr[i - 1]);
		counter[i - 1] += counter[i];
	}

	rep(i, N) printf("%lld\n", ans[i]);
}


