#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int n,k,f[100001],ans,d[100001];
vector<int> point[100001];

void dfs(int u){
	d[u]=1;for(int v:point[u])dfs(v),d[u]=max(d[u],d[v]+1);
	if(d[u]>=k&&f[u]!=1)d[u]=0,++ans;
}

int main(){
	scanf("%d%d",&n,&k);for(int i=1;i<=n;++i){scanf("%d",f+i);if(i!=1)point[f[i]].push_back(i);}
	for(int v:point[1])dfs(v);
	printf("%d",ans+(f[1]!=1));
}