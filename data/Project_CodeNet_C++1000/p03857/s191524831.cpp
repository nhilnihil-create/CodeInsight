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

/* -----  2018/04/25  Problem: ABC 049 C / Link: http://abc049.contest.atcoder.jp/tasks/abc049_c  ----- */
/* ------問題------

問題違うけど

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */
int dfs(int v, int p, int c, VVI &G, VI&color) {
	color[v] = c;
	FOR(i, 0, SZ(G[v])) {
		int nv = G[v][i];
		if (nv == p)continue;
		if (color[nv] == 0) {
			dfs(nv, v, c, G, color);
		}
	}

}

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int K, L;
	cin >> N>>K>>L;
	VI Qcolor(N,0);
	VVI QG(N);
	VVI LG(N);
	FOR(i, 0, K) {
		int a, b; cin >> a >> b;
		a--, b--;
		QG[a].push_back(b);
		QG[b].push_back(a);
	}

	VI Lcolor(N,0);
	FOR(i, 0, L) {
		int a, b; cin >> a >> b;
		a--, b--;
		LG[a].push_back(b);
		LG[b].push_back(a);
	}

	{
		int c = 0;
		FOR(i, 0, N) {
			if (Qcolor[i] == 0) {
				c ++;
				dfs(i, -1, c, QG, Qcolor);
			}
		}
	}
	{
		int c = 0;
		FOR(i, 0, N) {
			if (Lcolor[i] == 0) {
				c++;
				dfs(i, -1, c, LG, Lcolor);
			}
		}
	}
	map<PII, int>Map;
	FOR(i, 0, N) {
		Map[PII(Qcolor[i] ,Lcolor[i])] ++;
	}
	FOR(i, 0, N) {
		cout << Map[PII(Qcolor[i], Lcolor[i])] << endl;
	}

	return 0;
}
