#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int mod=1e9+7,maxn=1e6+10;
const int dx[10]={0,0,-1,1,-1,-1,1,1},dy[10]={-1,1,0,0,-1,1,-1,1};
ll tong[10],h,w,n,sum,tot;
pair<int,int> node[maxn];
map<pair<int,int>,int>mp;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main()
{
	scanf("%lld%lld%lld",&h,&w,&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		node[i].first=read(),node[i].second=read();
		mp[node[i]]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<8;j++)
		{
			int nx=node[i].first+dx[j];
            int ny=node[i].second+dy[j];
            if(nx>=1&&nx<=h&&ny>=1&ny<=w)
            {
            	pair<int,int>temp(nx,ny);
            	mp[temp]++;
			}
   		}
	tot=(h-2)*(w-2);
	map<pair<int,int>,int>::iterator it,ed=mp.end();
	for(it=mp.begin();it!=ed;it++)
	{
		int x=it->first.first;
		int y=it->first.second;
		int val=it->second;
		if(x>1&&x<h&&y>1&&y<w)
		{
			tong[val]++;
			sum++;
		}
	}
	tong[0]=tot-sum;
	for(int i=0;i<=9;i++)
		printf("%lld\n",tong[i]);
	return 0;
}