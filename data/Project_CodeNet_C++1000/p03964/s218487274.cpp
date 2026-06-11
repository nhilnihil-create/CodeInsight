#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define X first
#define Y second
#define pb push_back
#define max_el(x) max_element(x.begin(),x.end())-x.begin()
#define min_el(x) min_element(x.begin(),x.end())-x.begin()
#define mp make_pair
#define endl '\n'
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// DONT USE MEMSET, USE VECTORS

void solve(){
	int n;
	cin>>n;
	ll num,den;
	cin>>num>>den;
	for(int i=0;i<n-1;i++){
		// cout<<"num den "<<num<<" "<<den<<endl;
		ll nnum,nden;
		cin>>nnum>>nden;
		ll l = 1;
		ll h = 1e18/max(nnum,nden);
		ll ans = 1;
		while(l<=h){
			ll m = l + (h-l)/2;
			if(num <= m*nnum && den <= m*nden){
				ans = m;
				h = m-1;
			}
			else{
				l = m+1;
			}
		}
		// cout<<ans<<endl;
		num = nnum*ans;
		den = nden*ans;
	}
	cout<<num+den<<endl;
}

int main(){
	fastread;
	int t = 1;
	// cin>>t;
	for(int i=1;i<=t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
