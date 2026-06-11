#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
int mod = 1000000000+7;

int main(){

	ll n,a,b;
	cin>>n>>a>>b;
	ll x[n];
	rep(i,n)cin>>x[i];

	ll ans=0;
	rep(i,n-1){
		if((x[i+1]-x[i])*a>b)ans+=b;
		else ans+=(x[i+1]-x[i])*a;
	}

	cout<<ans<<endl;

	return 0;
}
