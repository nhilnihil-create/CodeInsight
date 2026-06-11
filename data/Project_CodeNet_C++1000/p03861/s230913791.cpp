#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	ll a,b,x; cin>>a>>b>>x;
	ll mx=b/x;
	ll mn=a/x;
	if(a%x==0) cout<<mx-mn+1<<endl;
	else cout<<mx-mn<<endl;
}