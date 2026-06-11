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

ll n,a[maxn];

bool rec(){
	if(n==1) return !(a[1]&1);
	ll tod=0,tev=0;
	for(int i=1;i<=n;i++) tod+=(a[i]&1);
	tev=n-tod;
	if(tev&1) return 1;
	if(tod>=2 || tod==0) return 0;
	ll gcc=0;
	for(int i=1;i<=n;i++){
		if(a[i]&1) a[i]--;
		if(a[i]==0) return 0;
		gcc=__gcd(gcc,a[i]);
	}
	for(int i=1;i<=n;i++) a[i]/=gcc;
	return !rec();
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<(rec() ? "First":"Second");

	return 0;
}










