#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	ll n,a,b; cin>>n>>a>>b;
	ll ans=(n-2)*(b-a)+1;
	if(ans<0) cout<<0<<endl;
	else cout<<ans<<endl;
}