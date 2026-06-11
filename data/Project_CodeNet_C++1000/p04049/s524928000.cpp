#include<bits/stdc++.h>
#define pb push_back
#define fr first
#define sc second
#define all(x) x.begin(), x.end()
#define skip continue
#define NAME "code"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
void faster(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
 
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
const ll MAXN = 2e3 + 123;
const ld EPS = 1e-12;
const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int n, k, ans = MAXN, d[MAXN];
vector<int> g[MAXN];
queue<int> q;

int bfs(){

	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int to : g[v]){
			if(d[to] == INF){
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}

	int res = 0;

	for(int i = 1; i <= n; ++i){
		res += d[i] > (k / 2);
		d[i] = INF;
	}
	
	return res;
}

void solve(){
	cin >> n >> k;

	for(int i = 1, x, y; i < n; ++i){
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}

	for(int i = 1; i <= n; ++i)
		d[i] = INF;

	if(k & 1){
		for(int v = 1; v <= n; ++v){
			for(int to : g[v]){
				q.push(v);
				q.push(to);
				d[v] = d[to] = 0;
				ans = min(ans, bfs());
			}
		}
	}
	else{
		for(int v = 1; v <= n; ++v){
			q.push(v);
			d[v] = 0;
			ans = min(ans, bfs());
		}
	}

	cout << ans;
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