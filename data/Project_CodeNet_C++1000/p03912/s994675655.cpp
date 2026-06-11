#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;

#define int int64_t

#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,x,...) x
#define REP1(i, s, cond, cal) for (signed i = signed(s); i cond; i cal)
#define REP2(i, s, n) REP1(i, s, < signed(n), ++)
#define REP3(i, n) REP2(i, 0, n)
#define rep(...) CHOOSE((__VA_ARGS__,REP1,REP2,REP3))(__VA_ARGS__)
#define rrep(i, s) rep(i, s, >= 0, --)

#define all(c) begin(c), end(c)
#define maxup(ans, x) (ans = (ans < x ? x : ans))
#define minup(ans, x) (ans = (ans > x ? x : ans))

#define breakif(cond) if(cond) break; else

using VV = vector<vector<int>>;
using V = vector<int>;
using P = pair<int, int>;
using IP = pair<int, P>;

template<typename T>
inline void input(vector<T>& v) { for (auto& x : v) cin >> x; }

signed main() {
	int n, m; cin >> n >> m;

	VV mods(m);
	rep(i, n) {
		int x; cin >> x;
		mods[x % m].push_back(x);
	}
	rep(i, m) sort(all(mods[i]));

	int ans = mods[0].size() / 2;
	if (m != 1 && m % 2 == 0) ans += mods[m / 2].size() / 2;
	rep(i, 1, (m + 1) / 2) {
		auto& a = mods[i];
		auto& b = mods[m - i];
		if (a.size() > b.size()) swap(a, b);
		int rem = b.size() - a.size();
		ans += a.size();
		rep(j, (signed)b.size() - 1) breakif(rem <= 1) if(b[j] == b[j + 1]) {
			ans++;
			rem -= 2;
			j++;
		}
	}
	cout << ans << endl;

	system("pause");
}