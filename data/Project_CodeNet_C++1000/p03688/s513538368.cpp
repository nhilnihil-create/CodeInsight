#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
void solve(){
	ll n,lo=100005,hi=0;
	cin>>n;
	vector<ll> v(n);
	for(ll i=0;i<n;i++){
		cin>>v[i];
		lo=min(lo,v[i]);
		hi=max(hi,v[i]);
	}
	if(hi-lo>1)
	cout<<"No";
	else if(lo==hi){
		if(v[0]==n-1)
		cout<<"Yes";
		else if(2*v[0]<=n)
		cout<<"Yes";
		else
		cout<<"No";
	}
	else{
		ll cnt=0;
		for(ll i=0;i<n;i++)
		if(v[i]==lo)
		cnt++;
		ll tr=(n-cnt)/2;
		if(!tr||hi<=cnt||hi>cnt+tr)
		cout<<"No";
		else
		cout<<"Yes";
	}
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll qc=1;
    for(ll i=1;i<=qc;i++)
    solve();
}
