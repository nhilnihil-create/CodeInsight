#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

vector<vector<ll>> g;
ll n, m, a, b, q, v[100008], d[100008], c[100008], ans[100008], ansd[100008];

void dfs(ll at, ll dx, ll cx){
	if(ansd[at] < dx){
		if(ans[at] == 0){
			ans[at] = cx;
		}
		ansd[at] = dx;
		zep(i, 0, g[at].size()){
			dfs(g[at][i], dx-1, cx);
		}
	}
}

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> m;
	g.resize(n);
	zep(i, 0, m){
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin >> q;
	zep(i, 0, q){
		cin >> v[i] >> d[i] >> c[i];
		v[i]--;
	}
	
	memset(ans, 0, sizeof(ans));
	memset(ansd, -1, sizeof(ansd));
	rrep(i, q-1, 0){
		dfs(v[i], d[i], c[i]);
	}
	
	zep(i, 0, n){
		print(ans[i])
	}
	return 0;
}