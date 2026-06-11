#include<bits/stdc++.h>
using namespace std;
const int N=310;
int n,m,a[N][N],rk[N][N],fans,ans,pos;
int cnt[N],t;

int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);fans=n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]),rk[i][a[i][j]]=j;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(rk[i][j]==1)
				cnt[j]++;
	for(int i=1;i<=m;i++)
		if(cnt[i]>ans)
		{
			ans=cnt[i];
			pos=i;
		}
	fans=min(fans,ans);
	t=1;
	while(t++!=m)
	{
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
			rk[i][pos]=m+1;
		for(int i=1;i<=n;i++)
		{
			int minn=m+1,mpos;
			for(int j=1;j<=m;j++)
				if(rk[i][j]<minn)
				{
					minn=rk[i][j];
					mpos=j;
				}
			cnt[mpos]++;
		}
		ans=0;
		for(int i=1;i<=m;i++)
			if(cnt[i]>ans)
			{
				ans=cnt[i];
				pos=i;
			}
		fans=min(ans,fans);
	}
	printf("%d",fans);
	return 0;
} 