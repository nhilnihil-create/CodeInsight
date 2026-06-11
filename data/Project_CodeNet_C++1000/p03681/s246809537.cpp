#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 3e5+5;
void solve(){
	ll n,m; 
	cin>>n>>m; 
	if(abs(n-m)>1){
		cout<<0<<endl;
		return ;
	}
	ll ans = 1;
	for(ll i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	}
	for(ll i=1;i<=m;i++){
		ans*=i;
		ans%=mod;
	} 
	if(n==m)ans*=2ll;
	ans%=mod;
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
