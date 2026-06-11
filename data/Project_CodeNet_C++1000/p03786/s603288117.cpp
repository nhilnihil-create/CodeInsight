#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;cin>>n;
	ll a[n];
	rep(i,n) cin>>a[i];
	sort(a,a+n);
	ll s[n+1];s[0]=0;
	int ans=1;
	rep(i,n){
		s[i+1]=s[i]+a[i];
	}
	for(int i=n-1;i>0;i--){
		if(s[i]*2<a[i]) break;
		else ans++;
	}

	cout<<ans<<"\n";
}