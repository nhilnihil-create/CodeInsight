#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma warning(disable : 4996)
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<random>
#include<array>


using namespace std;

#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n-1;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m-1;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define print(x) cout<<(x)<<'\n'
#define pe(x) cout<<(x)<<" "
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define lb(v,n) lower_bound(v.begin(), v.end(), (n))
#define ub(v,n) upper_bound(v.begin(), v.end(), (n))
//#define int long long
//#define double long double
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
std::random_device rd;
std::mt19937 mt(rd());
constexpr int MOD = 1e9+7; constexpr int MAX = 200020;
const double pi = acos(-1); constexpr double EPS = 1e-8;
constexpr ll INF = 1e18;

template<typename T>
struct SegmentTree {
	int n;
	T unit;
	vector<T>dat;
	function<T(T, T)> func;
	SegmentTree(const int N, T _unit, function<T(T, T)> _func)
		:unit(_unit), func(_func) {
		n = 1;
		//簡単のため、要素数を2のべき乗に
		while (n < N)n *= 2;
		dat.assign(2 * n, unit);
	}

	void update(int k, T a) {
		k += n - 1;//葉の節点
		dat[k] = a;
		//上りながら更新
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = func(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}
	T _query(int a, int b, int k, int l, int r) {
		//[a,b)と[l,r)が交差していなければ、funcに影響を与えない値を返す
		if (r <= a || b <= l)return unit;
		//[a,b)が[l,r)を完全に含んでいれば、この節点の値
		if (a <= l && r <= b)return dat[k];
		else {
			int vl = _query(a, b, k * 2 + 1, l, (l + r) / 2);
			int vr = _query(a, b, k * 2 + 2, (l + r) / 2, r);
			return func(vl, vr);
		}
	}
	//[a,b)
	T query(int a, int b) {
		return _query(a, b, 0, 0, n);
	}
};

void solve() {
	int N; cin >> N;

	auto f = [](ll a, ll b) {return (a + b)%MOD; };
	SegmentTree <ll> seg(N + 1, 0, f);
	seg.update(0, 1);
	seg.update(1, N);
	for (int i = 2; i <= N; i++) {
		ll tmp = (N - i+1);
		int r = max(0, i - 2);
		tmp += seg.query(0, r);
		tmp %= MOD;
		tmp += (ll)(N - 1)*(N - 1) % MOD;
		tmp %= MOD;
		tmp += seg.query(i - 1, i);
		tmp %= MOD;
		seg.update(i, tmp);
		//pe(i); print(seg.query(i, i + 1));
	}
	//REP(i, N + 1) {
	//	pe(i); print(seg.query(i, i + 1));
	//}
	print(seg.query(N, N + 1));
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	//while (q--)
	solve();
}

