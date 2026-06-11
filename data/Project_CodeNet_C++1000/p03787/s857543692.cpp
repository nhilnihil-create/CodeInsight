#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) {cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;}
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod=1000000007;
const int MAXN=100010, LOG=20;

int n, m, k, u, v, a, b;
ll x, y, z, ans;
int col[MAXN];
vector<int> G[MAXN];

bool dfs(int node, int c){
	bool res=1;
	col[node]=c;
	for (int v:G[node]){
		if (!col[v]) res&=dfs(v, 3-c);
		else res&=(col[v]!=col[node]);
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=n; i++) if (!col[i]){
		if (G[i].empty()) x++;
		else if (dfs(i, 1)) y++;
		else z++;
	}
	//cerr<<x<<' '<<y<<' '<<z<<endl;
	ans=2*x*n-x*x+z*z+2*y*z+2*y*y;
	cout<<ans<<'\n';
	
	return 0;
}
