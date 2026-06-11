// In the name of god
#include <bits/stdc++.h>
#pragma GCC optimze("02")
using namespace std;
using ll =long long;
const ll maxn=2e3+5,inf=1e18;
ll  n,m=inf,k,x,y,h[maxn],num[2][maxn];
bool mark[maxn];
vector <ll> adj[maxn];
pair <ll,ll> p[maxn];
void dfs(int u,int v){
	mark[u]=1;
	for(int j:adj[u]){
		if(!mark[j]&&j!=v){
			h[j]=h[u]+1;
			num[0][h[u]+1]++;
			dfs(j,v);
		}
	}
}
void dfs2(int u,int v){
	mark[u]=1;
	for(int j:adj[u]){
		if(!mark[j]&&j!=v){
			h[j]=h[u]+1;
			num[1][h[u]+1]++;
			dfs2(j,v);
		}
	}
}
void dfs3(int u){
	mark[u]=1;
	for(int j:adj[u]){
		if(!mark[j]){
			h[j]=h[u]+1;
			num[0][h[j]]++;
			dfs3(j);
		}
	}
}
int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		x--;
		y--;
		p[i]={x,y};
		adj[y].push_back(x);
		adj[x].push_back(y);
	}
	if(k%2==1){
		for(int i=1;i<n;i++){
			dfs(p[i].first,p[i].second);
			dfs2(p[i].second,p[i].first);
			x=0;
			for(int j=(k+1)/2;j<=n;j++){
				x+=num[0][j];
				x+=num[1][j];
			}
			m=min(m,x);
			for(int j=0;j<=n;j++){
				h[j]=0;
				num[0][j]=0;
				num[1][j]=0;
				mark[j]=0;
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			dfs3(i);
			x=0;
			for(int j=(k/2)+1;j<=n;j++){
				x+=num[0][j];
			}
			m=min(m,x);
			for(int j=0;j<=n;j++){
				h[j]=0;
				num[0][j]=0;
				num[1][j]=0;
				mark[j]=0;
			}
		}
	}
	cout<<m;
	
}
