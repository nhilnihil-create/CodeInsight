#include<bits/stdc++.h>
using namespace std;
int n,d[305][305];
long long ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&d[i][j]);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
	{
		bool f=0;
		for(int k=1;k<=n;k++)
		{
			if(i==k||j==k)continue;
			f|=d[i][j]==d[i][k]+d[j][k];
			if(d[i][k]+d[j][k]<d[i][j])
			{
				puts("-1");
				return 0;
			}
		}
		if(!f)ans+=d[i][j];
	}
    printf("%lld\n",ans);
    return 0;
}