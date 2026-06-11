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
ll n,t;
ll a[200005];
ll ans;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>t;
	for(int i=0;i<n;i++) cin>>a[i];
	ans+=t;
	for(int i=1;i<n;i++){
		ans+=t;
		if(a[i]<a[i-1]+t) ans-=a[i-1]+t-a[i]; 
	}
	cout<<ans;
	re 0;
}