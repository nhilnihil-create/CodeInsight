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

ll n,a[maxn],b[maxn];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n;
	ll sum=0;
	for(int i=0;i<n;i++) cin>>a[i], sum+=a[i];
	ll p=n*(n+1)/2;
	if(sum%p) return cout<<"NO", 0;
	ll k=sum/p;
	for(int i=0;i<n;i++) b[i]=a[(i+1)%n]-a[i]-k;
	for(int i=0;i<n;i++)if(b[i]>0 || (-b[i])%n) return cout<<"NO", 0;
	cout<<"YES"<<endl;

	return 0;
}










