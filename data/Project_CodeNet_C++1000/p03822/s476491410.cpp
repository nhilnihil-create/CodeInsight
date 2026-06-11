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

int n;
vector<int> g[MAXN];

int dfs(int v){
	vector<int> q;
	q.clear();

	for(int to : g[v]){
		q.pb(dfs(to));
	}

	sort(all(q));
	reverse(all(q));

	int res = g[v].size();
	int y = 0;
	for(int x : q){
		res = max(res, x + y + 1);
		y++;
	}

	return res;
}

void solve(){
	cin >> n;

	for(int i = 2, u; i <= n; ++i){
		cin >> u;
		g[u].pb(i);
	}

	cout << dfs(1);
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