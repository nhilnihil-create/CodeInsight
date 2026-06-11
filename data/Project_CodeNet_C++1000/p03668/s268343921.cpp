#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u32 = uint32_t;
using vb = vector<bool>;   using vvb = vector<vb>;
using vl = vector<ll>;     using vvl = vector<vl>;

#define REP(i,n) for(auto i = 0 * (n), i##_len = (n); i < i##_len; ++i)
#define ALL(c) (c).begin(), (c).end()
#define FOR(i,s,n) for(ll i=s, i##_len=(ll)(n); i<i##_len; ++i)


int main() {
	#ifdef INPUT_FROM_FILE
	ifstream cin("sample.in");
	ofstream cout("sample.out");
	#endif
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(50);

	ll n;
	cin >> n;

	vvl path(n);
	REP(i, n - 1) {
		ll x, y; cin >> x >> y;
		path[x - 1].push_back(y - 1);
		path[y - 1].push_back(x - 1);
	}

	function<ll(ll, ll)> recur = [&](ll cur, ll prev) {
		ll num = 0;
		for (ll next : path[cur]) if (next != prev) {
			num ^= recur(next, cur) + 1;
		}
		return num;
	};
	cout << (recur(0, -1) != 0 ? "Alice" : "Bob") << endl;

	return 0;
}