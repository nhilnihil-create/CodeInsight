#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int d[2005];
V<int> v[2005];
P<int,int> p[2005];
void dfs(int x){
	for(auto u:v[x])if(d[u]==-1){
		d[u]=d[x]+1;
		dfs(u);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k; 
	cin>>n>>k;
	rep(i,1,n){
		cin>>p[i].F>>p[i].S;
	}
	int mini=1e9;
	if(k&1){
		k/=2;
		rep(i,1,n){
			FOR(j,1,n)v[j].clear();
			rep(j,1,n)if(i!=j){
				v[p[j].S].PB(p[j].F);
				v[p[j].F].PB(p[j].S);
			}
			FILL(d,-1);
			d[p[i].F]=0;
			d[p[i].S]=0; 
			dfs(p[i].F);dfs(p[i].S);
			int ans=0;
			FOR(j,1,n)ans+=d[j]>k;
			gmin(mini,ans);
		}
	}else{
		rep(i,1,n){
			v[p[i].F].PB(p[i].S);
			v[p[i].S].PB(p[i].F);
		}
		k/=2;
		FOR(i,1,n){
			FILL(d,-1);
			d[i]=0;
			dfs(i);
			int ans=0;
			FOR(j,1,n)ans+=d[j]>k;
			gmin(mini,ans);
		}
	}
	cout<<mini<<'\n'; 
	RE 0;
}


