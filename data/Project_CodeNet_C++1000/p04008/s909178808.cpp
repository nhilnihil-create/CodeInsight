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
#define mp make_pair

typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=1e5+10, lg=23, mod=1e9+7, inf=1e18;

ll n,k,ans=0;
ll f[maxn];
vector<ll> son[maxn];
set<pll> dep;

void dfs(ll v=1,ll h=0){
	dep.insert({h,v});
	for(auto u:son[v]) dfs(u,h+1);
}

bool mk[maxn];
void dfb(ll v,ll h){
	if(mk[v]) return;
	mk[v]=1;
	dep.erase({h,v});
	for(auto u:son[v]) dfb(u,h+1);
}

void mak(ll v,ll h){
	for(int i=0;i<k-1;i++) v=f[v], h--;
	//cout<<v<<' '<<h<<endl;
	dfb(v,h);
	ans++;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		if(i>1) son[f[i]].pb(i);
	}
	if(f[1]!=1) f[1]=1, ans++;
	dfs();
	while(!dep.empty()){
		auto x=*(--dep.end());
		if(x.F<=k) break;
		mak(x.S,x.F);
	}
	cout<<ans<<endl;

	return 0;
}








 




