#include <bits/stdc++.h>

#define ll long long
#define sz(x) (int)x.size();

using namespace std;

ll n,k;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	ll ans=k;
	ll x=n-1;
	while(x--){
		ans*=k-1;
	}
	cout<<ans;
	
}