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
int g[205][205];
int n,m,k;
int dist[205][205];
set<int>wa[205];
void dij(int x){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	for(int i=1;i<=n;i++)dist[x][i]=1e9;
	dist[x][x]=0;
	q.push({0,x});
	while(!q.empty()){
		auto p = q.top();
		q.pop();
		int u = p.second , cst = p.first;
		for(auto i : wa[u]){
			int v = i;
			int w = g[u][v];
			if(cst + w < dist[x][v]){
				dist[x][v] = cst+w;
				q.push({dist[x][v],v});
			}

		}
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file();	
 	
 	scanf("%d %d %d",&n,&m,&k);

 	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)g[i][j]=1e9;
 	for(int i=1;i<=n;i++)g[i][i]=0;

 	std::vector<int> a(k);

 	for(auto &x:a)scanf("%d",&x);

 	for(int i=0;i<m;i++){
 		int a,b,c;
 		scanf("%d %d %d",&a,&b,&c);
 		g[a][b]=min(c,g[a][b]);
 		g[b][a]=min(c,g[b][a]);
 		wa[a].insert(b);
 		wa[b].insert(a);
 	}

 	for(int i=1;i<=n;i++)dij(i);

 	sort(all(a));
 	int ans = 1e9;
 	do{	
 		int curr = 0;
 		for(int i=1;i<sz(a);i++){
 			curr+=dist[a[i-1]][a[i]];
 		}
 		ans = min(ans,curr);
 	}while(next_permutation(all(a)));
 	printf("%d\n",ans );
}		
