#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define ll long long



using namespace std;

void file(){
	#ifndef ONLINE_JUDGE
    	freopen("in.txt", "r", stdin);
	#endif
}
int tc;
const int N=5e5+5,M=2e6+5,MOD=1e9+7,OO=1e9;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();	
	
	int n,m;

	scanf("%d %d",&n,&m);

	std::vector<vector<pair<int,int>>> g(n+1);
	std::vector<vector<int>> dist(n+1,vector<int>(n+1,1e9));
	for(int i=1;i<=n;i++)dist[i][i]=0;
	while(m--){
		int x,y,c;
		scanf("%d %d %d",&x,&y,&c);
		g[x].pb({y,c});
		g[y].pb({x,c});
		dist[x][y]=min(dist[x][y],c);
		dist[y][x]=min(dist[y][x],c);
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],
				dist[i][k]+dist[k][j]);
			}		
		}	
	}
	int ans = 0;
	std::vector<vector<bool>> vis(n+1,vector<bool>(n+1));
	for(int i=1;i<=n;i++){
		for(auto p : g[i]){
			int u = p.first;
			if(vis[i][u] || vis[u][i])continue;
			int c = p.second;
			vis[i][u]=1;
			vis[u][i]=1;
			if(dist[i][u]!=c && dist[u][i]!=c)ans++;
		}
	}

	printf("%d\n",ans );
	
}		
