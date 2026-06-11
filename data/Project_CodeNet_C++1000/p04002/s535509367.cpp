#include<bits/stdc++.h>
using namespace std;
int n,h,w;
map<long long,int>mp;
long long cnt[10];
int fx[9]={0,0,0,1,1,1,-1,-1,-1};
int fy[9]={0,-1,1,0,-1,1,0,-1,1};
bool in(int x,int y)
{
	if(x-1>=1 && x+1<=h && y-1>=1 && y+1<=w)return 1;
	return 0;
}
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	cnt[0]=1ll*(h-2)*(w-2);
	int x,y;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		for(int j=0;j<9;j++)
		{
			int xx=x+fx[j],yy=y+fy[j];
			if(!in(xx,yy))continue;
			long long p=1ll*xx*1000000000+yy;
			if(mp.find(p)!=mp.end())
			{
				cnt[mp[p]]--; cnt[++mp[p]]++;
			}
			else
				cnt[0]--,cnt[mp[p]=1]++;
		}
	}
	for(int i=0;i<=9;i++)
		printf("%lld\n",cnt[i]);
	return 0;
}
