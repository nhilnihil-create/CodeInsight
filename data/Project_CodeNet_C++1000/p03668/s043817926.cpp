#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>adj[100005];
ll dfs(ll x,ll p=-1){
	ll xo=0;
	for(auto it:adj[x]){
		if(it!=p){
			xo^=dfs(it,x);
		}
	}
	return 1+xo;
}
int main(){
	ll n;
	cin>>n;
	for(ll i=1;i<n;i++){
		ll a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ll ans=dfs(1);
	ans--;
	//cout<<ans<<endl;
	if(ans==0)cout<<"Bob"<<endl;
	else cout<<"Alice"<<endl;
}