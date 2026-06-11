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

ll n,a[2*maxn];
bool check(ll x){
	bool beg=(a[n]>=x);
	for(int i=1;i<=n-1;i++){
		if(i%2 && ((a[n-i]>=x)==beg || (a[n+i]>=x)==beg))       return beg;
		if((i+1)%2 && ((a[n-i]>=x)==!beg || (a[n+i]>=x)==!beg)) return !beg;
	}
	return (n%2 ? beg:!beg);
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=1;i<=2*n-1;i++) cin>>a[i];
	ll l=1,r=2*n-1;
	while(r-l>1){
		ll mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else           r=mid;
	}
	cout<<l<<endl;

	return 0;
}








 




