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

vector<ll> a;
int n; ll x;

ll check(){
	ll cnt = 0;
	ll red = 0;
	for(int i=0; i<n-1;i++){
		ll p = a[i] + a[i+1] - red;
		if(p <= x) {
			red = 0;
			continue;
		}
		cnt += p-x;
		// cout<<i<<" "<<p-x<<endl;
		red = min(p-x, a[i+1]);
	}
	return cnt;
}

void solve(){
	cin>>n>>x;
	a.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	cout<<check()<<endl;
	// ll l = 0;
	// ll h = 1e15;
	// ll ans = -1;
	// while(l<=h){
	// 	ll m = l + (h-l)/2;
	// 	if(check(m)){
	// 		ans = m;
	// 		h = m-1;
	// 	}
	// 	else{
	// 		l = m+1;
	// 	}
	// }

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
