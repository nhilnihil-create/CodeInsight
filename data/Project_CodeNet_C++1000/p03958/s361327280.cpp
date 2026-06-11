#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int k,t;cin>>k>>t;
	int a[t];
	rep(i,t) cin>>a[i];
	sort(a,a+t);
	if(t==1){
		cout<<k-1<<"\n";
		return 0;
	}
	int ans=a[t-1]-1-(k-a[t-1]);
	if(ans<0) cout<<0<<"\n";
	else cout<<ans<<"\n";
}
