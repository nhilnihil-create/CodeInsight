#include<iostream>
#include<cstring>
#include<cstdio>
#define inf 0X3f3f3f3f
#define N 100010
#define ll long long
using namespace std;
int num[N];
ll lf[N],rf[N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	for(int i=1;i<n;i++)
	{
		int x=num[i],y=num[i+1];
		if(x<y)
		{
			lf[1]+=(y-x);
			lf[x+1]+=(y+1)-(y-x);
			rf[x+1]--;
			lf[y+1]+=(y-x)-(y+1);
			rf[y+1]++;
		}
		else if(x>y)
		{
			lf[1]+=y+1;
			rf[1]--;
			lf[y+1]+=m-x+y-(y+1);
			rf[y+1]++;
			lf[x+1]+=y+1+m-(m-x+y);
			rf[x+1]--;
		}
	}
	lf[0]=rf[0]=0;
	for(int i=1;i<=m;i++) lf[i]+=lf[i-1];
	for(int i=1;i<=m;i++) rf[i]+=rf[i-1];
	ll ans=100000000000ll;
	for(int i=1;i<=m;i++) ans=min(ans,lf[i]+i*rf[i]);
	printf("%lld\n",ans);
	return 0;
}