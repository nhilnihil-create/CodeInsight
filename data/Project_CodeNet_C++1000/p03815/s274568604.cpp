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
	ll x;
	cin>>x;
	// if(x == 1){
	// 	cout<<1<<endl;
	// 	return;
	// }
	ll moves = 1;

	ll l = 1;
	ll h = x;

	while(l<=h){
		ll m = l + (h-l)/2;
		ll tot = m/2*11;
		if(m%2) tot += 6;
		if(tot >= x){
			moves = m;
			h = m-1;
		}
		else{
			l = m+1;
		}
	}

	cout<<moves<<endl;


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
