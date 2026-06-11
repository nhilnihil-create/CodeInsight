#include "bits/stdc++.h"
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

/* -----  2017/10/11  Problem: N18_f AGC010 C / Link: http://agc010.contest.atcoder.jp/tasks/agc010_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL N;
LL a[100005];
LL ans = 1;//okか
vector<vector<LL>>G;

LL f(LL u, LL p) {
	VL v;
	FOR(i, 0, SZ(G[u])) {
		if (G[u][i] != p)v.push_back(G[u][i]);
	}
	
	if (SZ(v) == 0)return a[u];//not ch

	LL sum = 0; LL maxv = -1;
	FOR(i, 0, SZ(v)) {
		LL t = f(v[i], u);
		sum += t;
		maxv = max(maxv, t);
	}
	if (sum < a[u]) { ans = 0; return 0; }//普通にしたが多い
	
	LL up = min(sum / 2, sum - maxv);
	LL res = sum - a[u];
	if (res > up) { ans = 0; return 0; }
	
	return sum - res * 2;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N)cin >> a[i];
	G = vector<vector<LL>>(N, vector<LL>());
	FOR(i, 0, N - 1) {
		LL a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if (N == 2) {
		cout << ((a[0]==a[1])?"YES":"NO") << endl;
		return 0;
	}
	LL root = -1;
	FOR(i, 0, N)if (SZ(G[i]) >= 2)root = i;
	LL res=f(root, -1);
	
	cout << ((ans&&res==0)?"YES":"NO") << "\n";

	return 0;
}