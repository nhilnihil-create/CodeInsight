#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200005;
int n,i,j,k,head[N],adj[N*2],nxt[N*2],sg[N];
bool v[N];
void dfs(int x,int dad)
{
	for(int y=head[x];y;y=nxt[y])
		if(adj[y]!=dad)
		{
			dfs(adj[y],x);
			sg[x]^=sg[adj[y]]+1;
		}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
	}
	dfs(1,-1);
	if(sg[1])
		printf("Alice");
	else
		printf("Bob");
	return 0;
}
