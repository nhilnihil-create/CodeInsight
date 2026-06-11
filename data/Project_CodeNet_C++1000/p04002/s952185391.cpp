#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;
struct Point
{
	int x,y;
	Point () {}
	Point (int x,int y):x(x),y(y) {}
	bool operator<(const Point &p)const
	{
		if(x!=p.x)
			return x<p.x;
		return y<p.y;
	}
	bool operator!=(const Point &p)const
	{
		return x!=p.x||y!=p.y;
	}
}p[1010101];
map <Point,bool> mp;
long long ans[10];
int main()
{
	int h,w,n,xx,yy,pn,cnt;
	scanf("%d%d%d",&h,&w,&n);
	pn=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&xx,&yy);
		mp[Point(xx,yy)]=true;
		for(int j=max(xx-2,1);j<=min(xx,h-2);j++)
			for(int k=max(yy-2,1);k<=min(yy,w-2);k++)
				p[++pn]=Point(j,k);
	}
	sort(p+1,p+pn+1);
	memset(ans,0,sizeof(ans));
	ans[0]=(long long)(h-2)*(w-2);
	for(int i=1;i<=pn;i++)
		if(i==1||p[i]!=p[i-1])
		{
			ans[0]--;
			cnt=0;
			for(int j=p[i].x;j<p[i].x+3;j++)
				for(int k=p[i].y;k<p[i].y+3;k++)
					if(mp.count(Point(j,k)))
						cnt++;
			ans[cnt]++;
		}
	for(int i=0;i<=9;i++)
		printf("%lld\n",ans[i]);
	return 0;
}