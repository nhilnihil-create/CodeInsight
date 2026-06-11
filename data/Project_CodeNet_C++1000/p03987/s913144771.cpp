#include<bits/stdc++.h>
using namespace std;
int seg[800005],t;
void up(int st,int ed,int lv,int po,int val)
{
	int md=(st+ed)/2;
	if(st>po || ed<po)
	{
		return;
	}
	if(st==po && ed==po)
	{
		seg[lv]=val;
		return;
	}
	up(st,md,lv*2,po,val);
	up(md+1,ed,lv*2+1,po,val);
	seg[lv]=max(seg[lv*2],seg[lv*2+1]);
}
int q(int st,int ed,int lv,int po)
{
	//printf("%d %d\n",st,ed);
	int md=(st+ed)/2;
	if(st>po)
	{
		return 0;
	}
	if(st>=1 && ed<=po)
	{
		return seg[lv];
	}
	return max(q(st,md,lv*2,po),q(md+1,ed,lv*2+1,po));
}
void upp(int st,int ed,int lv,int po,int val)
{
	int md=(st+ed)/2;
	if(st>po || ed<po)
	{
		return;
	}
	if(st==po && ed==po)
	{
		//printf("e%d %d\n",st,val);
		seg[lv]=val;
		return;
	}
	upp(st,md,lv*2,po,val);
	upp(md+1,ed,lv*2+1,po,val);
	seg[lv]=min(seg[lv*2],seg[lv*2+1]);
}
int qq(int st,int ed,int lv,int po)
{
	int md=(st+ed)/2;
	if(st>po)
	{
		return 1e9;
	}
	if(st>=1 && ed<=po)
	{
		//printf("tt%d %d %d\n",st,ed,seg[lv]);
		return seg[lv];
	}
	return min(qq(st,md,lv*2,po),qq(md+1,ed,lv*2+1,po));
}
long long lr[200005],rl[200005],val[200005];
main()
{
	scanf("%d",&t);
	for(int i = 1;i <= t;i++)
	{
		scanf("%lld",&val[i]);
	}
	for(int i = 1;i <= t;i++)
	{
		lr[i]=i-q(1,t,1,val[i]);
		up(1,t,1,val[i],i);
	}
	for(int i = 0;i < 800005;i++)
	seg[i]=t+1;
	//printf("gg");
	for(int i = t;i >= 1;i--)
	{
		rl[i]=qq(1,t,1,val[i])-i;
		upp(1,t,1,val[i],i);
	}
	long long sm=0;
	for(int i = 1;i <= t;i++)
	{
		sm+=lr[i]*rl[i]*val[i];
	}
	for(int i = 1;i <= t;i++)
	{
	//	printf("%d %d\n",lr[i],rl[i]);
	}
	printf("%lld",sm);
}