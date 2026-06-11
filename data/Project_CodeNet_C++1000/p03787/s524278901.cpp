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

const ll maxn=5e2+10, lg=17, mod=1e9+7, inf=1e18;

vector<ll>G[1<<lg];
ll n,m,a,b,c,v[1<<lg];
bool dfs(int u,int col){
	v[u]=col;
	bool ans=1;
	for(auto x:G[u]){
		if(!v[x]) ans&=dfs(x,3-col);
		else      ans&=(v[x]==3-col);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int v,u; cin>>v>>u;
		G[v].pb(u);
		G[u].pb(v);
	}
	for(int i=0;i++<n;)if(!v[i]){
		if(SZ(G[i])==0)   c++;
		else if(dfs(i,1)) a++;
		else              b++;
	}
	cout<<2*c*n-c*c+2*a+b*b+a*(a-1)*2+a*b*2<<endl;

	return 0;
}
















