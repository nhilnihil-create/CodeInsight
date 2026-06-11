#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,p; cin>>n>>p;
	vector<int> v(n);
	bool even=true;
	rep(i,n) {cin>>v[i]; if(v[i]%2!=0) even=false;}
	
	if(even&&p==1) cout<<0<<endl;
	else if(even&&p==0){
		ll ans=2;
		for(int i=1; i<n; i++){
			ans*=2;
		}
		cout<<ans<<endl;
	}
	else {
		ll ans=2;
		for(int i=1; i<n; i++){
			ans*=2;
		}
		cout<<ans/2<<endl;
	}
}