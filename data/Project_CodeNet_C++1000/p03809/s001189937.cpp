#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
using namespace std;
int n,flag=0;
vector<ll> a(100009), pat[100009],used(100009);
ll solve(ll x){
	used[x]=1;
	int fl = 0;
	for(int i=0;i<pat[x].size();i++){
		if(used[ pat[x][i] ] == 0)fl++;
	}
	if(fl == 0){
		return a[x];
	}
	vector<ll> subs;
	ll tot = 0;
	for(int i=0;i<pat[x].size();i++){
		if(used[pat[x][i]]==0){
			ll nu = solve( pat[x][i] ) ;
			if(nu==-1)return -1;
			subs.pb(nu);
			tot+=nu;
		}
	}
	sort( subs.begin(),subs.end());
	if( a[x]*2 < tot ){
		flag = -1;
		return -1;
	}
	else if(tot < a[x]){
		flag = -1;
		return -1;
	}
	else if( subs[subs.size()-1] > a[x]){
		flag = -1;
		return -1;
	}
	else{
		return 2*a[x]-tot;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		ll fr,to;
		cin>>fr>>to;
		pat[fr].pb(to);
		pat[to].pb(fr);
	}
	if(n==2){
		if(a[1]==a[2]){
			cout<<"YES"<<endl;
			return 0;
		}
		else{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	ll good;
	for(int i=1;i<=n;i++){
		if(pat[i].size()>1){
			good = i;
			i = n+1;
		}
	}
	ll an = solve(good);
	if( an == 0 && flag == 0){
		cout<<"YES"<<endl;
		return 0;
	}
	else{
		cout<<"NO"<<endl;
		return 0;
	}
	return 0;
}