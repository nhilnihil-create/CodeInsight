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
ll gcd(ll a,ll b){
	if(!b) re a;
	else re gcd(b,a%b);
}
ll lcm(ll a,ll b){
	re a/gcd(a,b)*b;
}
ll ans=1;
signed main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	while(n--){
		ll t;
		cin>>t;
		ans=lcm(ans,t);
	}
	cout<<ans;
	re 0;
}