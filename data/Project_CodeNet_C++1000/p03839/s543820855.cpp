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

const ll maxn=1e5+10, lg=64, mod=1e9+7, inf=1e18;

ll n,k,a[maxn];
ll l[maxn],r[maxn],ps[maxn];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ps[i]=ps[i-1]+a[i];
		l[i]=l[i-1]+max(0ll,a[i]);
	}
	for(int i=n;i>=1;i--) r[i]=r[i+1]+max(0ll,a[i]);
	ll ans=0;
	for(int i=0;i<=n-k;i++) ans=max(ans,l[i]+r[i+k+1]+max(0ll,ps[i+k]-ps[i]));
	cout<<ans<<endl;

	return 0;
}







 





