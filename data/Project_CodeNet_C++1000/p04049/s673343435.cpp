#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <sstream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1e9;
vector<int> dist[2020];
struct egde{
    int u,v;
}e[2020];
int vis[2020];
int N,K;
int dfs1(int pos,int dis)
{
	int res = 0;
	if(dis>K/2) res++;
	vis[pos] = 1;
	for(int i = 0;i < dist[pos].size();i++){
		if(!vis[dist[pos][i]]){
			res += dfs1(dist[pos][i],dis+1);
			//cout<<"res:"<<res<<endl;
		}
	}
	return res;
}
int main()
{
	scanf("%d%d",&N,&K);
	for(int i = 1;i <= N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		dist[a].push_back(b);
		dist[b].push_back(a);
		e[i].u = a;
		e[i].v = b;
	}
	if(K%2==0){
		int ans = INF;
		for(int i = 1;i <= N;i++){
			memset(vis,0,sizeof(vis));
			vis[i] = 1;
			ans = min(dfs1(i,0),ans);
		}
		cout<<ans<<endl;
	}
	else{
		int ans = INF;
		for(int i = 1; i<= N-1;i++){
            memset(vis,0,sizeof(vis));
            vis[e[i].u] = 1;
            vis[e[i].v] = 1;
            ans = min(ans,dfs1(e[i].u,0)+dfs1(e[i].v,0));
		}
		cout<<ans<<endl;
	}
	return 0;
}
