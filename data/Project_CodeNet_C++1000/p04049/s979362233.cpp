#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=2005;
int n,k;
vector<int> vec[N];
int f[N][N];
int tmp[N];
int tot[N];
int ans=0;
void dfs (int x,int fa)
{
	f[x][0]=1;tot[x]=1;
	int siz=vec[x].size();
	for (int u=0;u<siz;u++)
	{
		int y=vec[x][u];
		if (y==fa) continue;
		dfs(y,x);
		for (int i=0;i<=k;i++) tmp[i]=0;
		for (int i=0;i<=min(tot[x],k);i++)
		for (int j=0;j<=min(tot[y],k-1);j++)
		{
			int l=i+j+1;
			if (l>k) break;
			tmp[max(i,j+1)]=max(tmp[max(i,j+1)],f[x][i]+f[y][j]);
		}
		for (int i=0;i<=k;i++) f[x][i]=max(f[x][i],tmp[i]);
		tot[x]+=tot[y];
	}
	//printf("x:%d\n",x);
	for (int i=0;i<=k;i++) 
	{
	//	printf("%d ",f[x][i]);
		ans=max(ans,f[x][i]);
	}
	//printf("\n");
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int u=1;u<n;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);vec[y].push_back(x);
	}
	dfs(1,0);
	printf("%d\n",n-ans);
	return 0;
}