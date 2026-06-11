#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using u32 = uint32_t;
using vi = vector<int>;    using vvi = vector<vi>;
using vb = vector<bool>;   using vvb = vector<vb>;
using vl = vector<ll>;     using vvl = vector<vl>;
using vd = vector<double>; using vvd = vector<vd>;

#define REP(i,n) for(auto i = 0 * (n), i##_len = (n); i < i##_len; ++i)
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,s,n) for(ll i=s, i##_len=(ll)(n); i<i##_len; ++i)
#define TEN(x) ((ll)1e##x)
const ll mod = TEN(9) + 7;
// Union find : O(α(V))
// verified : 
class UnionFind {
	typedef size_t U;
	// v[i] : i番目の頂点が根 ? i番目の頂点の属する木のサイズ * -1
	//                       : i番目の頂点の親のindex
	vector<int32_t> v;
public:
	UnionFind(U n) : v(n, -1) {}
	U find(U x) { return v[x] < 0 ? x : (v[x] = find((U)v[x])); }
	bool same(U x, U y) { return find(x) == find(y); }
	U size(U x) { return (U)-v[find(x)]; }
	void unite(U x, U y) {
		x = find(x); y = find(y);
		if (x != y) {
			if (-v[x] < -v[y]) swap(x, y);
			v[x] += v[y];
			v[y] = x;
		}
	}
};

int main() {
#ifdef INPUT_FROM_FILE
	ifstream cin("sample.in");
	ofstream cout("sample.out");
#endif
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(50);

	ll n, m; cin >> n >> m;
	vl x(n); REP(i, n) cin >> x[i];

	vl y(TEN(5) + 1, 0); REP(i, n) y[x[i]]++;
	vl y_mod(m, 0); REP(i, TEN(5) + 1) y_mod[i % m] += y[i];
	vl y_mod_use(m, 0);
	ll cnt = y_mod[0] / 2;
	FOR(i, 1, m / 2 + m % 2) {
		y_mod_use[i] = y_mod_use[m - i] = min(y_mod[i], y_mod[m - i]);
		cnt += y_mod_use[i];
	}
	if (m % 2 == 0) cnt += y_mod[m / 2] / 2;
	FOR(i, 1, m) if (i * 2 != m) if (y_mod[i] - y_mod_use[i] > 0){

		ll yobun = 0;
		for (ll j = i; j < TEN(5) + 1; j += m) {
			if (y[j] % 2 == 1) yobun++;
		}


		y_mod[i] -= yobun;
		if (yobun < y_mod_use[i]) {
			y_mod[i] -= y_mod_use[i] - yobun;
		}
		cnt += y_mod[i] / 2;
	}

	cout << cnt << endl;

	return 0;
}