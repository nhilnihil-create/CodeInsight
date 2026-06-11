#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
#include<vector> 
using namespace std;
#define N 100002
vector<int> g[N];
int parent[N],dis[N];
int n,num;
void dfs(int cur,int par){
	int i,now;
	dis[cur] = dis[par] + 1;
//	cout<<cur<<' '<<dis[cur]<<endl;
	for( i=0;i<g[cur].size();i++ )
	{
		now = g[cur][i];
		if( now == par )
			continue;
		parent[now]=cur;
		dfs(now,cur);
	}
}
// 求一棵子树中的节点数量 
void dfs1(int cur,int par){
	int i,now;
	num++;
	for( i=0;i<g[cur].size();i++ )
	{
		now = g[cur][i];
		if( now == par )
			continue;
		dfs1(now,cur);
	}
}
int main(){
	int i,to,from,k,cur,cnt;
	cin>>n;
	for( i=0;i<n-1;i++ ){
		cin>>to>>from;
		g[to].push_back(from);
		g[from].push_back(to);
	}
	dis[0]=-1;
	dfs(1,0);
	k=dis[n]-1;
//	cout<<k<<endl;
	cur = n;
	cnt=0;
	while( 1 )
	{
		if( cnt>=k/2 )
			break;
		cur = parent[cur];
		cnt++;
	}
	num=0;
	dfs1(cur,parent[cur]);
//	cout<<num<<endl;
	if( num>=n-num )
		cout<<"Snuke";
	else
		cout<<"Fennec";
	return 0;
}
