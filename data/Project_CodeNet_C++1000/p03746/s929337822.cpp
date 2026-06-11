#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define MAX 100100
inline int read()
{
	int x=0;bool t=false;char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=true,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return t?-x:x;
}
vector<int> E[MAX],ans1,ans2;
bool vis[MAX];
int n,m,S,T;
void dfs(int u,vector<int> &A)
{
	vis[u]=true;A.push_back(u);
	for(int v:E[u])if(!vis[v]){dfs(v,A);break;}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		S=read(),T=read();
		E[S].push_back(T);
		E[T].push_back(S);
	}
	vis[S]=vis[T]=true;
	dfs(S,ans1);dfs(T,ans2);
	printf("%d\n",ans1.size()+ans2.size());
	while(!ans1.empty())printf("%d ",ans1.back()),ans1.pop_back();
	for(int x:ans2)printf("%d ",x);puts("");
	return 0;
}
