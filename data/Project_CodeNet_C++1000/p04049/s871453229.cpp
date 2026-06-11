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

const ll maxn=2e3+10, mod=1e9+7, inf=1e18;

ll n,k;
vector<ll> g[maxn];

ll dfs(ll v,ll p=0,ll h=0){
	if(h==k/2) return 1;
	ll sum=1;
	for(auto u:g[v])if(u!=p) sum+=dfs(u,v,h+1);
	return sum;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n>>k;
	for(int i=1;i<n;i++){
		ll v,u; cin>>v>>u;
		g[v].pb(u);
		g[u].pb(v);
	}
	ll ans=inf;
	if(k%2==0) for(int i=1;i<=n;i++) ans=min(ans,n-dfs(i));
	else for(int i=1;i<=n;i++)for(auto j:g[i]) ans=min(ans,n-(dfs(i,j)+dfs(j,i)));
	cout<<ans<<endl;

	return 0;
}







