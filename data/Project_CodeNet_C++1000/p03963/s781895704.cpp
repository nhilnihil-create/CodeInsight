#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll ans = 0;
	ll n,k;
	cin>>n>>k;
	
	if(n == 1){
		cout<<k<<endl;
		return 0;
	}
		
	ans  = k;
	ans *=  (ll)pow((k-1),(n-1));
	cout<<ans<<endl; 
}

