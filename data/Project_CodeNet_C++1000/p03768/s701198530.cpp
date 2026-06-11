#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<string.h>
#include<math.h>
#include<queue>
#include<cstring>
#include<new>
#include<cmath>
#include<sstream>
#define fo(i,w,n) for(int i=(int) w;i<(int) n;i++)
#define qi queue<int>
#define vi vector<int>
#define ll long long
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define mp make_pair
#define sz size()
#define em empty()
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define sett(a,b) memset(a,b,sizeof(a))
#define copy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
int n,m,q,u,v,ans[101010];
vi ed[101010];
int p[101010],dist[101010],c[101010],mindis[101010];
void dfs(int x,int y,int color){
	if(y<=mindis[x])return;
	mindis[x]=y;
	if(ans[x]==0)ans[x]=color;
	fo(i,0,ed[x].sz)dfs(ed[x][i],y-1,color);
}
int main(){
	cin>>n>>m;
	fo(i,0,n)mindis[i]=-1;
	fo(i,0,m){
		cin>>u>>v;
		--u;--v;
		ed[u].pb(v);
		ed[v].pb(u);
	}
	cin>>q;
	fo(i,0,q)cin>>p[i]>>dist[i]>>c[i];
	for(int i=q-1;i>=0;i--)dfs(p[i]-1,dist[i],c[i]);
	fo(i,0,n)cout<<ans[i]<<endl;
	return 0;
}