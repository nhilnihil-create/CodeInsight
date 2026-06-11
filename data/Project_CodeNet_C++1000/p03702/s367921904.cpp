#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fi first
#define se second
#define pb push_back
#define mk make_pair

using namespace std;
typedef long long ll;
ll mod = 998244353;
vector<ll> m;

int main() {
	fastio;
	ll n,a,b;
	cin>>n>>a>>b;
	m.resize(n);
	for(ll i=0;i<n;i++){
		cin>>m[i];
	}
	ll lo = 0, hi = 1e10;
	ll ans = hi;
	while(lo<=hi){
		ll mid = (hi+lo)/2;
		ll c = 0;
		for(ll i=0;i<n;i++){
			if(mid*b<m[i]){
				ll r = m[i]-mid*b;
				c += (r+a-b-1)/(a-b);
			}
		}
		
		if(c<=mid){
			ans = mid;
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
		
	}
	
	cout<<ans<<"\n";
	
}




