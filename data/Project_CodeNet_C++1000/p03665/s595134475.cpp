#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n,p;cin>>n>>p;
	ll even=0,odd=0;
	rep(i,n){
		int a;cin>>a;
		if(a%2==0) even++;
		else odd++;
	}
	if(odd==0){
		ll ans=pow(2,even);
		if(p==0) cout<<ans<<"\n";
		else cout<<0<<"\n";
	}
	else{
		ll ans=pow(2,odd-1)*pow(2,even);
		cout<<ans<<"\n";
	}
}