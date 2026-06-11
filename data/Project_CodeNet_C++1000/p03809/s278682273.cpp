#include<bits/stdc++.h>
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(), x.end()
#define skip continue
#define NAME "code"
#define tabs(a, b) ((a<b) ? (b-a) : (a-b))
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
void faster(){
   	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
const ull INF = 1e9;
const ll MOD = 1e9 + 7;
const ll MAXN = 3e5 + 123;
const ld EPS = 1e-12;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};
 
int n, A[MAXN], c[MAXN], root, sum;
vector<pair<int, int>> g[MAXN];

void dfs(int v, int pr){
	c[v] = A[v] * ((g[v].size() != 1) + 1);

	int *b_edge = NULL;

	for(int i = 0; i < g[v].size(); ++i){
		if(g[v][i].fr != pr){
			dfs(g[v][i].fr, v);
			c[v] -= c[g[v][i].fr];
			g[v][i].sc = c[g[v][i].fr];
		}
		else{
			b_edge = &g[v][i].sc;
		}
	}

	if(b_edge != NULL)
		*b_edge = c[v];

	if(c[v] < 0){
		cout << "NO\n";
		exit(0);
	}
}

void check(int v){
	int sum = 0, mx = 0;

	for(int i = 0; i < g[v].size(); ++i){
		sum += g[v][i].sc;
		mx = max(g[v][i].sc, mx);
	}

	if(sum & 1 || mx > sum / 2){
		cout << "NO\n";
		exit(0);
	}
}

void solve(){
	cin >> n;

	for(int i = 1; i <= n; ++i){
		cin >> A[i];
	}

	for(int i = 2, u, v; i <= n; ++i){
		cin >> u >> v;
		g[u].pb({v, 0});
		g[v].pb({u, 0});
	}

	if(n == 2){
		cout << ((A[1] == A[2]) ? "YES" : "NO");
		return;
	}

	for(int i = 1; i <= n; ++i)
		if(g[i].size() != 1)
			root = i;

	dfs(root, 0);

	if(c[root] != 0){
		cout << "NO\n";
		return;
	}

	for(int i = 1; i <= n; ++i)
		if(g[i].size() > 1)
			check(i);

	cout << "YES\n";
}
 
int main(){
 
	faster();
 
	int T = 1;
	// cin >> T;
	
	while(T--){
		solve();
	}
 
	return 0;
}