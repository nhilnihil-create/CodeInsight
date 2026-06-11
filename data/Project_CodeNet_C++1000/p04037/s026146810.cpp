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

const ll maxn=1e5+10, mod=1e9+7, inf=1e18;

ll n,a[maxn];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,greater<ll>());
	ll x=1,y=1; while(x<n && a[x+1]>y) x++, y++;
	ll l=a[x]-y,r=-1; while(x<=n && a[x]>=y) x++, r++;
	cout<<(l%2 || r%2 ? "First\n":"Second\n");

	return 0;
}







