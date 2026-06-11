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
	map<int,int> pf;
	for(int i=1;i<=n;i++){
		int p = i;
		for(int j=2;j*j<=p;j++){
			while(p%j == 0){
				pf[j] += 1;
				p/=j;
			}
		}
		if(p>1) pf[p] += 1;
	}	
	ll su = 1;
	for(auto x:pf){
		su *= x.Y+1;
		su %= mod;
		// cout<<x.X<<" "<<x.Y<<endl;
	}
	cout<<su<<endl;

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
