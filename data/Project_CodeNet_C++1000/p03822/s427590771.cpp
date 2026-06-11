#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define li long long
#define ld long double
#define x first
#define y second
#define pt pair<int, int>
#define pll pair<ll, ll>
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
int a[N], ans;
vector<int> g[N];


bool read(){
	if(scanf("%d", &n) != 1)
		return 0;
	forn(i, n)
		g[i] = vector<int>();
	ans = 1;
	forn(i, n - 1){
		scanf("%d", &a[i]);
		g[--a[i]].pb(i + 1);
	}
	return 1;
}

int dfs(int v){
	vector<int> ch;
	for (auto u : g[v])
		ch.pb(dfs(u));
	sort(all(ch), greater<int>());
	int mx = 0;
	forn(i, sz(ch))
		mx = max(mx, ch[i] + i + 1);
	return mx;
}


void solve(){
	printf("%d\n", dfs(0));
}


int main(){
	#ifdef _DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	while(read())
		solve();
	return 0;
}