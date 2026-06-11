// Do you knOW what it feels like?

		// To be TorTured by your own MinD?
	
	// I don't wanna feel the PAIN.

// I BeG you to KILL me, pleASE...

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2")
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

const ll maxn=1e5+10, lg=17, mod=1e9+7, inf=1e18;

ll n,m,q[maxn],tt;
vector<ll> g[maxn];
bool mk[maxn];
void fff(ll v){
	mk[v]=1, q[++tt]=v;
	for(auto u:g[v])if(!mk[u]){ fff(u); break; }
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n>>m;
	while(m--){
		ll v,u; cin>>v>>u;
		g[v].pb(u), g[u].pb(v);
	}
	fff(1);
	reverse(q+1,q+tt+1);
	tt--;
	fff(1);
	cout<<tt<<endl;
	for(int i=1;i<=tt;i++) cout<<q[i]<<' ';
	
	return 0;
}
















