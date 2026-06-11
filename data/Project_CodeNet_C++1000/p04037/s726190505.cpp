#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

const int N=3e5+5;
int n,a[N],tot,ok;
int xj=1e9+7,yj=1e9+7;
pair<int,int> p[N],jd;

void init()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;++i) scanf("%d",&a[i]);
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	p[++tot]=make_pair(0,n);p[++tot]=make_pair(a[n],n);
	for(i=n;i>1;--i)
		if(a[i]<a[i-1])
		{
			p[++tot]=make_pair(a[i],i-1);
			p[++tot]=make_pair(a[i-1],i-1);
		}
	p[++tot]=make_pair(a[1],0);
}

void calc1(pair<int,int> x,pair<int,int> y)
{
	if(x.second>=x.first&&y.second<=x.first)
	{
		ok=1;
		jd=make_pair(x.first-1,x.first-1);
	}
}
void calc2(pair<int,int> x,pair<int,int> y)
{
	if(x.first<=x.second&&y.first>=x.second)
	{
		ok=1;
		jd=make_pair(x.second-1,x.second-1);
	}
}

void cc1(pair<int,int> x,pair<int,int> y)
{
	if(x.second>=jd.second&&y.second<=jd.second)
		xj=min(xj,x.first-jd.first);
}
void cc2(pair<int,int> x,pair<int,int> y)
{
	if(x.first<=jd.first&&jd.first<=y.first)
		yj=min(yj,y.second-jd.second);
}

void prework()
{
	int i;
	for(i=1;i<tot;++i)
	{
		if(p[i].first==p[i+1].first)
			calc1(p[i],p[i+1]);
		else
			calc2(p[i],p[i+1]);
		if(ok) break;
	}
	
	for(i=1;i<tot;++i)
	{
		if(p[i].first==p[i+1].first)
			cc1(p[i],p[i+1]);
		else
			cc2(p[i],p[i+1]);
	}
	if(xj%2==1&&yj%2==1) printf("Second\n");
	else printf("First\n");
}

int main()
{
	init();prework();
	return 0;
}