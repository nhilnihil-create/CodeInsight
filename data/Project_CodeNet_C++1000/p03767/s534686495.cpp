#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
	
int main(){
	ll n;
	cin>>n;
	ll ar[3*n];
	for(int i=0;i<3*n;i++){
	 	cin>>ar[i];
	}
	
	sort(ar,ar+3*n,greater<ll>());
	
	ll ans = 0;	 
	int ind = 1;
	for(int i=0;i<n;i++){
		ans+=(ar[ind]);
		ind+=2;
	}
	 	 
	cout<<ans;
	return 0;
}
