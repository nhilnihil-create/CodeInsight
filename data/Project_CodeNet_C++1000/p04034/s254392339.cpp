#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n,m;cin>>n>>m;
	int x[m],y[m];
	rep(i,m) cin>>x[i]>>y[i];

	int l[n],red[n];
	rep(i,n){
		l[i]=1;
		red[i]=0;
		if(i==0) red[i]=1;
	}

	rep(i,m){
		if(red[x[i]-1]) red[y[i]-1]=1;
		l[x[i]-1]--;
		l[y[i]-1]++;
		if(l[x[i]-1]==0) red[x[i]-1]=0;
	}

	ll ans=0;
	rep(i,n) ans+=(ll)red[i];

	cout<<ans<<"\n";
}