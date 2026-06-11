#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	ll a,b,c; cin>>a>>b>>c;
	ll cnt=0;
	while(1){
		if(a%2==1||b%2==1||c%2==1){cout<<cnt<<endl; return 0;}
		else if(a==b&&b==c){cout<<-1<<endl; return 0;}
		else{
			cnt++;
			ll ta,tb,tc;
			ta=b/2+c/2; tb=a/2+c/2; tc=a/2+b/2;
			a=ta; b=tb; c=tc;
		}
	}
}