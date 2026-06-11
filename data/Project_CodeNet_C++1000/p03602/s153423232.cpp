#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iostream>
#define LL long long
using namespace std;
int a[310][310],n;
LL ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			bool flag=false;
			for(int k=1;k<=n;k++) if(i!=k&&j!=k)
			{
				if(a[i][j]>a[i][k]+a[k][j]) return puts("-1"),0;
				if(a[i][j]==a[i][k]+a[k][j]) flag=true;
			}
			if(!flag) ans+=a[i][j];
		}
	printf("%lld",ans);
}