#include <bits/stdc++.h>
using namespace std;

#define WA {puts("No");return 0;}
#define MAXN 501

struct Data
{
	int id,v;
	bool operator<(const Data &d)const
	{
		return v<d.v;
	}
}data[MAXN];

int num[MAXN*MAXN],pos=1,n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&data[i].v);
		num[data[i].v]=i;
		data[i].id=i;
	}
	sort(data+1,data+n+1);
	for(int i=1;i<=n;++i)
	{
		int cnt=1;
		while(cnt<data[i].id)
		{
			while(num[pos]!=0)++pos;
			num[pos]=data[i].id;
			++cnt;
		}
		if(pos>data[i].v)WA
	}
	pos=n*n;
	for(int i=n;i>=1;--i)
	{
		int cnt=0;
		while(cnt<n-data[i].id)
		{
			while(num[pos]!=0)--pos;
			num[pos]=data[i].id;
			++cnt;
		}
		if(pos<data[i].v)WA
	}
	puts("Yes");
	for(int i=1;i<=n*n;++i)printf("%d ",num[i]);
	puts("");
}