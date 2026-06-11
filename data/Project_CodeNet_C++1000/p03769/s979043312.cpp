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

const ll maxn=4e2+10, lg=22, mod=1e9+7, inf=1e18;

ll n,m,t,a[50],ans[100];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n; n++;
	for(;n>1;n>>=1) m+=(a[++t]=n&1);
	ll l=m+1,r=m;
	for(int i=t,j=0;i;i--){
		ans[++r]=++j;
		if(a[i]) ans[--l]=++j;
	}
	cout<<r*2<<endl;
	for(int i=1;i<=r;i++) cout<<ans[i]<<' ';
	for(int i=1;i<=r;i++) cout<<i<<' ';

	return 0;
}
















