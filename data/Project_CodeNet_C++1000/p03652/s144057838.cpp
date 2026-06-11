#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
ll v[305][305],vis[305];
void solve(){
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
	for(ll j=1;j<=m;j++)
	cin>>v[i][j];
	ll c=0,res=pow(10,10);
	while(c<m){
		vector<ll> cnt(m+1,0);
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=m;j++)
			if(!vis[v[i][j]]){
				cnt[v[i][j]]++;
				break;
			}
		}
		ll hi=0,hell=0;
		for(ll i=1;i<=m;i++){
			hi=max(hi,cnt[i]);
			if(hi==cnt[i])
			hell=i;
		}
		vis[hell]=1;
		res=min(res,hi);
		c++;
	}
	cout<<res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll qc=1;
    for(ll i=1;i<=qc;i++)
    solve();
}
