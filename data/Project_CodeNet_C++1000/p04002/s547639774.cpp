#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  __MAKE_TIME__  Problem: __PROBLEM__ / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W, N; cin >> H >> W >> N;
	int DX[] = { 0, 0, 1, -1, 1, 1, -1, -1,0 };    int DY[] = { 1, -1, 0, 0, 1, -1, 1, -1,0 };

	map<PII, int>Map;
	FOR(i, 0, N) {
		int y, x; cin >> y >> x;
		y--, x--;
		FOR(k, 0, 9) {
			int ny = y + DY[k];
			int nx = x + DX[k];
			if (1 <= ny && ny < H - 1 && 1 <= nx && nx < W - 1) {
				Map[PII(ny, nx)]++;
			}
		}
	}
	VL ans(10, 0);
	const auto MM = Map;
	for (auto m : MM) {
		ans[m.second]++;
	}
	ans[0] = ((H - 2)*(W - 2) - accumulate(ALL(ans), 0LL));
	FOR(i, 0, 10) {
		cout << ans[i] << endl;
	}

	return 0;
}