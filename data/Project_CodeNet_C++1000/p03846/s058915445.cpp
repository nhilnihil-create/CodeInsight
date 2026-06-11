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

ll mod = 1e9+7;

ll fpow(ll a, ll b, ll md){
	ll res = 1;
	a = (a%md);
	while(b>0){
		if(b%2==1){
			res = (res*a)%md;
		}
		b = b/2;
		a = (a*a)%md;
	}
	return res%md;
}

void solve(){
	int n;
	cin>>n;
	map<int,int> cnt;
	int r = n-1;
	for(int i=0;i<n;i++){
		cnt[abs(r-i)] += 1;
		r--;
		int u;
		cin>>u;
		cnt[u] -= 1;
	}
	for(auto x:cnt){
		if(x.Y != 0){
			cout<<0<<endl;
			return;
		}
	}
	int s = cnt.size();
	if(n%2) s-=1;

	
	cout<<fpow(2,s,mod)<<endl;
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
