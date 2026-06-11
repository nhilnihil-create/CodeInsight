#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000000000000000

ll mypow(ll a,ll b){
	ll num=1;
	while(b>0){
		b--;
		num*=a;
	}
	return num;
}

int main(){
	ll n,p;cin>>n>>p;
	vector<ll> a(n);
	
	ll even=0,odd=0,ans;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		a[i]%=2;
		if(a[i]==1){odd++;}
		else{even++;}
	}

	if(even==n){
		if(p==0){ans=mypow(2,n);}
		else{ans=0;}
	}else{ans=mypow(2,n-1);}

	cout<<ans<<endl;

	return 0;
}