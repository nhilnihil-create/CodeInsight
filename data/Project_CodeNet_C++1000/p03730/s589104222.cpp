#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int main(){
	ll a,b,c;
	cin>>a>>b>>c;
	ll x=1e5,d=a;
	while(x--){
		if(a%b==c){
			cout<<"YES";
			return 0;
		}
		a+=d;
	}
	cout<<"NO";

	
	
}