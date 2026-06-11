#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;
const ll m=1e9+7;

int main(){
	int n; cin>>n;
	ll ans=1;
	for(ll i=1; i<=n; i++){
		ans=(ans*i)%m;
	}
	cout<<ans<<endl;
}