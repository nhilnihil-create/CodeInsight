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

const ll maxn=1e6+10, lg=21, mod=1e9+7, inf=1e18;

ll n,we[maxn];

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
	for(int i=1;i<=n;i++){
 		ll x; cin>>x;
 		we[x]=i;
    }
	set<ll> s; s.insert(0), s.insert(n+1);
	ll ans=0;
    for(int j=1;j<=n;j++){ int i=we[j];
        auto it2=s.upper_bound(i);
        auto it1=it2; it1--;
        ans+=(i-*it1)*(*it2-i)*j;
        s.insert(i);
    }
    cout<<ans<<endl;

	return 0;
}

























