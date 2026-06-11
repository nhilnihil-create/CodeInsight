#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=400005;
int n,m,i,j,k,head[N],adj[N],nxt[N],col[N],num,num1,num2;
long long ans;
void dfs(int x)
{
	++k;
	for(int y=head[x];y;y=nxt[y])
		if(col[adj[y]]==col[x])
			j=0;
		else if(col[adj[y]]==0)
		{
			col[adj[y]]=-col[x];
			dfs(adj[y]);
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		adj[i*2-1]=k;
		nxt[i*2-1]=head[j];
		head[j]=i*2-1;
		adj[i*2]=j;
		nxt[i*2]=head[k];
		head[k]=i*2;
	}
	for(i=1;i<=n;++i)
		if(col[i]==0)
		{
			++num;
			col[i]=1;
			j=1,k=0;
			dfs(i);
			if(j)
			{
				if(k==1)
					++num1;
				else
					++num2;
			}
		}
	ans=1ll*(num-num1)*(num-num1);
	ans+=1ll*num2*num2;
	ans+=1ll*num1*num1;
	ans+=2ll*num1*(n-num1);
	printf("%lld",ans);
	return 0;
}
