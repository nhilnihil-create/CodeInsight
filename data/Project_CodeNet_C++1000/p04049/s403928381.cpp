#include <iostream>
//#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define pb(x) push_back(x)
#define F first
#define S second
using namespace std;
const int N=2000;
vector<int> g[N];
int n;
bool used[N];
int k;
vector<pair<int,int> >a;

int dfs(int u,int p,int maxd,int d){
	int ret=0;
	if(d>maxd){	
		ret++;
		}
	for(auto x:g[u]){
		if(x!=p){
			ret+=dfs(x,u,maxd,d+1);
		}
	}
	return ret;
}
void solve(){
	cin>>n>>k;
	int x;
	int y;
	loop(i,1,n){
		cin>>x>>y;
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
		a.pb(make_pair(x,y));
	}
	int ans=n;
	if(k&1){
		for(auto i:a){
			ans=min(ans,dfs(i.F,i.S,k/2,0)+dfs(i.S,i.F,k/2,0));
		}	
	}
	else{
		loop(i,0,n){
//			cout<<dfs(i,-1,k/2,0)<<endl;
			ans=min(ans,dfs(i,-1,k/2,0));
		}
	}
	cout<<ans<<endl;
}
int main(){
	solve();
}


