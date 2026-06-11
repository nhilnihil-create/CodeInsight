#include<bits/stdc++.h>
using namespace std;
const int maxn=45;
const int zero=4000;
const int INF=0x3f3f3f3f;
int n,a[maxn],b[maxn],val[maxn],cost[maxn],dp1[zero*2+5],dp2[zero*2+5],ans;
void solve(int s)
{
	memset(dp1,-1,sizeof(dp1));
	dp1[val[s]+zero]=cost[s];
	for(int i=s+1;i<=n;i++)
	{
		memset(dp2,0x3f,sizeof(dp2));
		for(int j=0;j<=zero*2;j++)
		{
			if(dp1[j]!=-1) dp2[j]=dp1[j];
			int pre=j-val[i];
			if(0<=pre&&pre<=zero*2&&dp1[pre]!=-1)
				dp2[j]=min(dp2[j],dp1[pre]+cost[i]);
			if(dp2[j]==INF) dp2[j]=-1;
		}
		for(int j=0;j<=zero*2;j++)
			dp1[j]=dp2[j];
	}
	if(dp1[zero]!=-1)
		ans=min(ans,dp1[zero]);
}
void fl()
{
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
}
int main()
{
//	  fl();
	int Ma,Mb;
	scanf("%d%d%d",&n,&Ma,&Mb);
	memset(dp1,-1,sizeof(dp1));
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&b[i],&cost[i]);
		val[i]=b[i]*Ma-a[i]*Mb;
	}
	ans=INF;
	for(int i=1;i<=n;i++)
		solve(i);
	printf("%d\n",ans==INF?-1:ans);
	return 0;
}
