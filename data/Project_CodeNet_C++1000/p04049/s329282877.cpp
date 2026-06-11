#include <bits/stdc++.h>
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define ll long long
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define VAR(v, i) __typeof( i) v=(i)
#define forit(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
 
using namespace std;
 
const int maxn = (int)5e3 + 100;
const int mod = (int)1e9 + 7;
const int P = (int) 1e6 + 7; 
const double pi = acos(-1.0);
 
#define inf mod
 
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   
typedef vector<ll> Vll;               
typedef vector<pair<int, int> > vpii;
typedef vector<pair<ll, ll> > vpll;                        

int n, d, ans = inf, cnt, p[maxn], dp[maxn][maxn];
vi g[maxn];

int dist(int a, int b){
	if(a == b) return 0;
	int &res = dp[a][b];
	if(res != -1) return res;
	res = inf;
	if(p[a]) res = min(res, dist(p[a], b) + 1);
	if(p[b]) res = min(res, dist(a, p[b]) + 1);
	return res;
}

void dfs(int v, int par){
	p[v] = par;
	for(auto to : g[v])
		if(to != par)
			dfs(to, v);
}
void solve(){
	scanf("%d%d", &n, &d);
	forn(i, 1, n - 1){
		int u, v;	
		scanf("%d%d", &u, &v);
		g[u].pb(v);
		g[v].pb(u);
	}
	memset(dp, -1, sizeof(dp));
	dfs(1, 0);
	forn(root, 1, n){
		if(!(d & 1)){
			cnt = 0;
			forn(go, 1, n)
				if(dist(root, go) > d / 2) cnt++;
			ans = min(ans, cnt);
		}else{
			for(auto to : g[root]){
				cnt = 0;
				forn(i, 1, n)
					if(min(dist(root, i), dist(to, i)) > d / 2)
						cnt++;
				ans = min(ans, cnt);
			}
		}
	}
	printf("%d", ans);
}
int main () {
	int t = 1;
	while(t--)
		solve(); 
}