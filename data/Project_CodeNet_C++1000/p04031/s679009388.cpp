#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
ll n;
ll a[105];
ll ans=1e18;
signed main(){
	ios_base::sync_with_stdio(0); 
	cin>>n;
	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll x=-100;x<=100;x++){
		ll cur=0;
		for(ll i=0;i<n;i++) cur+=(x-a[i])*(x-a[i]);
		ans=min(ans,cur);
	}
	cout<<ans;
	re 0;
}