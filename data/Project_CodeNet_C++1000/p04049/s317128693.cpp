#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define N 200002
struct edge{int to,nxxt;}e[N];
int n,k,head[N],cnt=1,dep[2002],a[N][2];
inline void ins(int u,int v){e[cnt].to=v;e[cnt].nxxt=head[u];head[u]=cnt++;}
void df5(int te,int la)
{
	for(int i=head[te];i;i=e[i].nxxt)
	{
		int j=e[i].to;if(j==la)continue;
		dep[j]=dep[te]+1;df5(j,te);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		ins(x,y);ins(y,x);a[i][0]=x,a[i][1]=y;
	}
	if(k%2==0)
	{
		int ans=n;
		for(int i=1;i<=n;i++)
		{
			dep[i]=0;df5(i,i);
			int tsu=0;
			for(int j=1;j<=n;j++)if(dep[j]>k/2)tsu++;
			ans=min(ans,tsu);
		}
		printf("%d\n",ans);return 0;
	}
	else
	{
		int ans=n;
		for(int i=1;i<n;i++)
		{
			int x=a[i][0],y=a[i][1],tsu=0;
			memset(dep,-1,sizeof(dep));dep[x]=0;df5(x,y);
			for(int j=1;j<=n;j++)if(dep[j]>k/2)tsu++;
			memset(dep,-1,sizeof(dep));dep[y]=0;df5(y,x);
			for(int j=1;j<=n;j++)if(dep[j]>k/2)tsu++;
			ans=min(ans,tsu);
		}
		printf("%d\n",ans);
	}
}
