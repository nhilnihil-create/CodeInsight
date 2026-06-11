#include<bits/stdc++.h>
#define LL long long
#define pii pair<LL,LL>
#define fir first
#define sec second
#define mp make_pair
using namespace std;
map<pii,LL> a;
LL X[100010],Y[100010],ans[50];
int main()
{
	LL H,W,N,tot,x,y,i;
	scanf("%lld %lld %lld",&H,&W,&N);
	for(i=1;i<=N;i++)
	{
		scanf("%lld %lld",&X[i],&Y[i]);
		a[mp(X[i],Y[i])]=1LL;
	}
	
	memset(ans,0,sizeof(ans));
	for(i=1;i<=N;i++)
	{
		x=X[i];y=Y[i];
		if(x+2<=H&&y+2<=W)
		{
			tot=a[mp(x,y)]+a[mp(x,y+1)]+a[mp(x,y+2)]+a[mp(x+1,y)]+a[mp(x+1,y+1)]+a[mp(x+1,y+2)]+a[mp(x+2,y)]+a[mp(x+2,y+1)]+a[mp(x+2,y+2)];
			ans[tot]++;
		}
		if(x+2<=H&&1<=y-1&&y+1<=W)
		{
			tot=a[mp(x,y-1)]+a[mp(x,y+1)]+a[mp(x+1,y-1)]+a[mp(x+1,y)]+a[mp(x+1,y+1)]+a[mp(x+2,y-1)]+a[mp(x+2,y)]+a[mp(x+2,y+1)]+a[mp(x,y)];
			ans[tot]++;
		}
		if(x+2<=H&&1<=y-2&&y<=W)
		{
			tot=a[mp(x,y-2)]+a[mp(x,y-1)]+a[mp(x,y)]+a[mp(x+1,y-2)]+a[mp(x+1,y-1)]+a[mp(x+1,y)]+a[mp(x+2,y-2)]+a[mp(x+2,y-1)]+a[mp(x+2,y)];
			ans[tot]++;
		}
		if(1<=x-1&&x+1<=H&&y+2<=W)
		{
			tot=a[mp(x-1,y)]+a[mp(x-1,y+1)]+a[mp(x-1,y+2)]+a[mp(x,y)]+a[mp(x,y+1)]+a[mp(x,y+2)]+a[mp(x+1,y)]+a[mp(x+1,y+1)]+a[mp(x+1,y+2)];
			ans[tot]++;
		}
		if(1<=x-1&&x+1<=H&&1<=y-1&&y+1<=W)
		{
			tot=a[mp(x-1,y-1)]+a[mp(x-1,y)]+a[mp(x-1,y+1)]+a[mp(x,y-1)]+a[mp(x,y)]+a[mp(x,y+1)]+a[mp(x+1,y-1)]+a[mp(x+1,y)]+a[mp(x+1,y+1)];
			ans[tot]++;
		}
		if(1<=x-1&&x+1<=H&&1<=y-2)
		{
			tot=a[mp(x-1,y-2)]+a[mp(x-1,y-1)]+a[mp(x-1,y)]+a[mp(x,y-2)]+a[mp(x,y-1)]+a[mp(x,y)]+a[mp(x+1,y-2)]+a[mp(x+1,y-1)]+a[mp(x+1,y)];
			ans[tot]++;
		}
		if(1<=x-2&&y+2<=W)
		{
			tot=a[mp(x-2,y)]+a[mp(x-2,y+1)]+a[mp(x-2,y+2)]+a[mp(x-1,y)]+a[mp(x-1,y+1)]+a[mp(x-1,y+2)]+a[mp(x,y)]+a[mp(x,y+1)]+a[mp(x,y+2)];
			ans[tot]++;
		}
		if(1<=x-2&&1<=y-1&&y+1<=W)
		{
			tot=a[mp(x-2,y-1)]+a[mp(x-2,y)]+a[mp(x-2,y+1)]+a[mp(x-1,y-1)]+a[mp(x-1,y)]+a[mp(x-1,y+1)]+a[mp(x,y-1)]+a[mp(x,y)]+a[mp(x,y+1)];
			ans[tot]++;
		}
		if(1<=x-2&&1<=y-2)
		{
			tot=a[mp(x-2,y-2)]+a[mp(x-2,y-1)]+a[mp(x-2,y)]+a[mp(x-1,y-2)]+a[mp(x-1,y-1)]+a[mp(x-1,y)]+a[mp(x,y-2)]+a[mp(x,y-1)]+a[mp(x,y)];
			ans[tot]++;
		}
	}
	tot=0ll;for(i=1;i<=9;i++){ans[i]/=i;tot+=ans[i];}
	ans[0]=(H-2LL)*(W-2LL)-tot;
	for(i=0;i<=9;i++)printf("%lld\n",ans[i]);
	return 0;
}