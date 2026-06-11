// Do you knOW what it feels like?

		// To be TorTured by your own MinD?
	
	// I don't wanna feel the PAIN.

// I BeG you to KILL me, pleASE...

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("Os")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=1e5+10, lg=22, mod=1e9+7, inf=1e18;

ll n,m,q;
ll vt[maxn],d[maxn],c[maxn],dp[maxn],col[maxn];
vector<ll> g[maxn];
void dfs(ll v,ll d,ll c){
	if(!col[v]) col[v]=c;
	if(dp[v]>=d || d==0) return;
	dp[v]=d;
	for(auto x:g[v]) dfs(x,d-1,c);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<m;++i){
		ll v,u;	cin>>v>>u;
		g[u].pb(v), g[v].pb(u);
	}
	cin>>q;
	for(int i=0;i<q;++i)    cin>>vt[i]>>d[i]>>c[i];
	for(int i=q-1;i>=0;--i) dfs(vt[i],d[i],c[i]);
	for(int i=1;i<=n;++i)   cout<<col[i]<<endl;

	return 0;
}
















