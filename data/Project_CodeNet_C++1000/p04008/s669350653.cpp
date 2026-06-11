#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define ll long long
using namespace std;
ll deg[114514], tak[114514], par[114514];
vector<ll> to[114514];
signed main(){
	ll n,k;
	cin>>n>>k;
	vector<ll> a;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a.pb(x-1);
		to[x-1].pb(i);
		to[i].pb(x-1);
		par[i] = x-1;
		deg[i]++;
		if(i>0 || x-1 == 0)deg[x-1]++;
	}
	ll ans = 0;
	if(a[0] != 0){
		ans++;
		a[0] = 0;
		par[0]=0;
	}
	if(k==1){
		for(int i=1;i<n;i++){
			if(a[i] != 0)ans++;
		}
		cout<<ans<<endl;
		return 0;
	}
	queue< int > que;
	for(int i=1;i<n;i++){
		if(deg[i]==1)que.push(i);
	}
	while(!que.empty()){
		ll ci = que.front();
		que.pop();
		if(tak[ci] == k-1 && par[ci] != 0){
			ans ++ ;
			tak[ci] = -1;
		}
		for(int i=0;i<to[ci].size();i++){
			ll di = to[ci][i];
			if( deg[di] > 1 ){
				tak[di] = max(tak[di], tak[ci] + 1 );
				deg[di]--;
				//cout<<di<<" "<<deg[di]<<endl;
				if(deg[di] == 1 && di != 0){
					que.push(di);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}