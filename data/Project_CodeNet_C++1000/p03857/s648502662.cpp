#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int res=0;
	char ch=getchar();
	while(ch>'9'||ch<'0')ch=getchar();
	while(ch>='0'&&ch<='9')
	res=(res<<1)+(res<<3)+(ch^48),ch=getchar();
	return res;
} 
int road[200005];
int rail[200005];
int ans[200005];
int find_road(int x)
{
	if(x!=road[x])
	road[x]=find_road(road[x]);
	return road[x];
}
void uni_road(int x,int y)
{
	int m=find_road(x),n=find_road(y);
	road[n]=m;
}
int find_rail(int x)
{
	if(x!=rail[x])
	rail[x]=find_rail(rail[x]);
	return rail[x];
}
void uni_rail(int x,int y)
{
	int m=find_rail(x),n=find_rail(y);
	rail[n]=m;
}
int main()
{
	int n=read(),k=read(),l=read();
	int num_road=k,num_rail=l;
	for(int i=1;i<=n;i++)
	road[i]=i,rail[i]=i;
	for(register int i=1;i<=k;i++)
	{
		int x=read(),y=read();
		uni_road(x,y);
		num_road--;
	}
	for(register int i=1;i<=l;i++)
	{
		int x=read(),y=read();
		uni_rail(x,y);
		num_rail--;
	}
//	for(register int i=1;i<=n;i++)
//	{
//		int x=find_road(i),y=find_rail(i),ans=0;
//		for(register int j=1;j<=n;j++)
//		if(find_road(j)==x&&find_rail(j)==y)
//		ans++;
//		printf("%d ",ans);
//	}
	for(int i=1;i<=n;i++)
	find_road(i),find_rail(i);
	map<pair<int,int>,int>mp;
	for(int i=1;i<=n;i++)
	{
		mp[make_pair(road[i],rail[i])]++;
	}
	for(int i=1;i<=n;i++)
	cout<<mp[make_pair(road[i],rail[i])]<<" ";
	return 0;
}