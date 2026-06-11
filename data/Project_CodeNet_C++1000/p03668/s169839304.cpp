#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define li long long
#define ld long double
#define x first
#define y second
#define pt pair<int, int>
#define pll pair<li, li>
#define forn(i, t) for(int i = 0; i < (t); i++)
#define fore(i, f, t) for(int i = (f); i < (t); i++)
#define forr(i, f, t) for(int i = (f) - 1; i >= (t); i--)
#define all(x) (x).begin(), (x).end()
#define ins insert

using namespace std;


const int INF = 1e9;
const int MOD = 1e9 + 7;
const li INF64 = 1e18;
const ld EPS = 1e-7;

mt19937 myrand(time(NULL));

const int N = 100 * 1000 + 13;

int n;
vector<int> g[N];


bool read(){
	if(scanf("%d", &n) != 1)
		return 0;
	forn(i, n)
		g[i].clear();
	forn(i, n - 1){
		int f, t;
		scanf("%d%d", &f, &t);
		--f, --t;
		g[f].pb(t);
		g[t].pb(f);
	}
	return 1;
}

int dp[N];

void dfs(int v, int p = -1){
	dp[v] = 0;
	int cnt = 0;
	for (auto u : g[v]) if (u != p){
		++cnt;
		dfs(u, v);
		dp[v] ^= dp[u] + 1;
	}
}

void solve(){
	dfs(0);
	printf(dp[0] ? "Alice\n" : "Bob\n");
}


int main(){
	#ifdef _DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	while(read())
		solve();
	return 0;
}