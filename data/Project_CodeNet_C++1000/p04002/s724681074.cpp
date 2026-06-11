#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cerr << #a << " = " << a << endl;

template<typename T> void setmax(T& x, T y) {x = max(x, y);}
template<typename T> void setmin(T& x, T y) {x = min(x, y);}

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int h, w;
LL ans[10];
	
inline bool ok(int x, int y)
{
	return x >= 1 && y >= 1 && x <= h - 2 && y <= w - 2;
}
	
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	
	cin >> h >> w;
	
	int n;
	cin >> n;
	vector<PII> cand;
	set<PII> S;
	while(n--)
	{
		int x, y;
		cin >> x >> y;
		S.insert({x, y});
		FOR(i, 0, 3) FOR(j, 0, 3)
			if (ok(x - i, y - j))
				cand.PB({x - i, y - j});
	}
	
	sort(ALL(cand));
	cand.resize(unique(ALL(cand)) - cand.begin());
	
	for(auto lol: cand)
	{
		int x = lol.X, y = lol.Y;
		int tut = 0;
		FOR(i, 0, 3) FOR(j, 0, 3)
			tut += S.count({x + i, y + j});
		ans[tut]++;
	}
	
	FOR(i, 1, 10) ans[0] += ans[i];
	ans[0] = (h - 2) * (LL) (w - 2) - ans[0];
	FOR(i, 0, 10) cout << ans[i] << endl;
		
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}

