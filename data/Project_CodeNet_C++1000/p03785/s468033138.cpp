#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	ll n,c,k;cin>>n>>c>>k;
	ll t[n];
	rep(i,n) cin>>t[i];
	sort(t,t+n);
	ll ans=1,cnt=0,l=t[0]+k;
	rep(i,n){
		cnt++;
		if(cnt>c||l<t[i]){
			ans++;
			l=t[i]+k;
			cnt=1;
		}
	}
	cout<<ans<<"\n";
}