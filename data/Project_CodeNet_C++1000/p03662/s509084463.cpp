//#include<bits/stdc++.h>
//using namespace std;
//const int MAXN=100005;
//int N;
//vector<int>adj[MAXN];
//int dist[2][MAXN];
//int type;
//int cnt;
//void dfs(int i,int last=-1)
//{
//	if(last!=-1)
//		dist[type][i]=dist[type][last]+1;
//	for(int j=0;j<adj[i].size();j++)
//		if(adj[i][j]!=last)
//			dfs(adj[i][j],i);
//}
//int main()
//{
//	scanf("%d",&N);
//	for(int i=0;i<N-1;i++)
//	{
//		int x,y;
//		scanf("%d%d",&x,&y);
//		adj[x].push_back(y);
//		adj[y].push_back(x);
//	}
//	type=0;
//	dfs(1);
//	type=1;
//	dfs(N);
//	for(int i=1;i<=N;i++)
//		if(dist[0][i]<=dist[1][i])
//			cnt++;
//	printf("%s\n",cnt>N/2?"Fennec":"Snuke");
//	return 0;
//}
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int N;
int frst;
vector<int>adj[MAXN];
vector<int>vec;
int cnt[MAXN];
void dfs(int i,int last)
{
	cnt[i]=1;
	vec.push_back(i);
	if(i==N)
		frst=vec[(vec.size()+1)/2];
	for(int j=0;j<adj[i].size();j++)
	{
		if(adj[i][j]==last)
			continue;
		dfs(adj[i][j],i);
		cnt[i]+=cnt[adj[i][j]];
	}
	vec.pop_back();
}
int main()
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	printf("%s\n",cnt[frst]*2>=N?"Snuke":"Fennec");
	return 0;
}