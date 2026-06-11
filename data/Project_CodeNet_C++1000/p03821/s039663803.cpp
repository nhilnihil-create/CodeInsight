#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	int n;cin>>n;
	ll a[n],b[n],c[n];

	rep(i,n) {
		cin>>a[i]>>b[i];
		c[i]=-(a[i]%b[i]);
		if(a[i]%b[i]!=0) c[i]+=b[i];
	}
/*
	rep(i,n) cout<<c[i]<<" ";
	cout<<"\n";
*/
	for(int i=n-1;i>0;i--){	
		if(c[i-1]<c[i]){
			ll cnt=(c[i]-c[i-1])/b[i-1];
			if((c[i]-c[i-1])%b[i-1]!=0) cnt++;
			c[i-1]+=b[i-1]*cnt;
		}
	}
/*
	rep(i,n) cout<<c[i]<<" ";
	cout<<"\n";
*/
	cout<<c[0]<<"\n";

}