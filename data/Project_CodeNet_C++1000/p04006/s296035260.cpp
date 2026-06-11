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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn=2e3+10, lg=21, mod=1e9+7, inf=1e18;

ll n,x,a[maxn],mnn[maxn];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n>>x;
	for(int i=0;i<n;i++) cin>>a[i], mnn[i]=inf;
	ll ans=inf;
	for(int ca=0;ca<n;ca++){
		for(int i=0;i<n;i++) mnn[i]=min(mnn[i],a[(i-ca+n)%n]);
		ll nans=x*ca;
		for(int i=0;i<n;i++) nans+=mnn[i];
		ans=min(ans,nans);
	}
	cout<<ans<<endl;

	return 0;
}






