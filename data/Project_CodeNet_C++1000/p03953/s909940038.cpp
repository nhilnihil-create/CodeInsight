#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")

#define F first
#define S second
#define pb push_back
#define SZ(x) (ll)(x.size())
#define all(x) x.begin(),x.end()
#define MP make_pair

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=1e5+10, maxm=5e3+10, lg=60, mod=1e9+7, inf=1e18;

ll n,m,k,a[maxn],par[maxn][lg+1];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i], par[i][0]=i;
	cin>>m>>k;
	while(m--){
		ll x; cin>>x;
		swap(par[x-1][0],par[x][0]);
	}
	for(int j=1;j<=lg;j++)for(int i=1;i<n;i++) par[i][j]=par[par[i][j-1]][j-1];
	ll nw=a[1];
	for(int i=1;i<n;i++){
		cout<<nw<<endl;
		ll p=i; for(int j=0;j<=lg;j++)if(k>>j&1) p=par[p][j];
		nw+=a[p+1]-a[p];
	}
	cout<<nw<<endl;
	
	return 0;
}




