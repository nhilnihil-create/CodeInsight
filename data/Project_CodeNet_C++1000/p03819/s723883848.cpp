#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<math.h>
using namespace std;

const int N=3e5+5;
const int M=1e5+5;
int n,m,now;
pair<int,int> p[N];

struct Tree_Array
{
	int c[N];
	int lowbit(int x)
	{
		return x&(-x);
	}
	
	void update(int pos,int add)
	{
		while(pos<=m)
		{
			c[pos]+=add;
			pos+=lowbit(pos);
		}
	}
	
	int query(int pos)
	{
		int ret=0;
		while(pos)
		{
			ret+=c[pos];
			pos-=lowbit(pos);
		}
		return ret;
	}
};
Tree_Array SS;

int cmp(pair<int,int> x,pair<int,int> y)
{
	return x.second-x.first<y.second-y.first;
}
void init()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		scanf("%d%d",&p[i].first,&p[i].second);
	sort(p+1,p+n+1,cmp);
}

void work()
{
	int i,j,ans;
	for(i=1;i<=m;++i)
	{
		ans=0;
		for(now;now<n&&p[now+1].second-p[now+1].first+1<=i;++now)
			SS.update(p[now+1].first,1),SS.update(p[now+1].second+1,-1);
		for(j=i;j<=m;j+=i) ans+=SS.query(j);
		printf("%d\n",ans+n-now);
	}
}

int main()
{
	init();work();
	return 0;
}