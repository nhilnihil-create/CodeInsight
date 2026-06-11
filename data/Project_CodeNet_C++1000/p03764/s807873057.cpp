#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/11/29  Problem: 071_arc_b / Link: https://arc071.contest.atcoder.jp/tasks/arc071_b  ----- */
/* ------問題------


-----問題ここまで----- */
/* -----解説等-----

なんかほんとは簡単にできた気がする

----解説ここまで---- */

LL W, H;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> W >> H;
	VL x(W);
	FOR(i, 0, W) {
		cin >> x[i];
	}
	VL y(H);
	FOR(i, 0, H) {
		cin >> y[i];
	}

	LL xsum = 0, bef;
	FOR(i, 1, W) {
		(xsum += bef) %= MOD;
		(xsum += (x[i] - x[i - 1])*i % MOD) %= MOD;
		(bef += (x[i] - x[i - 1])*i % MOD) %= MOD;
	}
	bef = 0;
	LL ysum = 0;
	FOR(i, 1, H) {
		(ysum += bef) %= MOD;
		(ysum += (y[i] - y[i - 1])*i % MOD) %= MOD;
		(bef += (y[i] - y[i - 1])*i % MOD) %= MOD;
	}
	ans = (xsum*ysum) % MOD;
	cout << ans << "\n";

	return 0;
}
