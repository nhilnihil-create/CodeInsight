#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<cmath>
#include<functional>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void sort(int &a,int &b)
{
	if(a>b)
		swap(a,b);
}
void open(const char *s)
{
#ifndef ONLINE_JUDGE
	char str[100];
	sprintf(str,"%s.in",s);
	freopen(str,"r",stdin);
	sprintf(str,"%s.out",s);
	freopen(str,"w",stdout);
#endif
}
int rd()
{
	int s=0,c;
	while((c=getchar())<'0'||c>'9');
	do
	{
		s=s*10+c-'0';
	}
	while((c=getchar())>='0'&&c<='9');
	return s;
}
int upmin(int &a,int b)
{
	if(b<a)
	{
		a=b;
		return 1;
	}
	return 0;
}
int upmax(int &a,int b)
{
	if(b>a)
	{
		a=b;
		return 1;
	}
	return 0;
}
ll a1[100010];
ll a2[100010];
int a[100010];
void add(ll *a,int x,int y,int v)
{
	a[x]+=v;
	a[y+1]-=v;
}
int main()
{
//	open("arc077e");
	int n,m;
	scanf("%d%d",&n,&m);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(i>=2)
		{
			if(a[i]>=a[i-1])
			{
				add(a1,a[i-1]+1,a[i],-1);
				add(a2,a[i-1]+1,a[i],a[i]+1);
				add(a2,a[i]+1,m,a[i]-a[i-1]);
				add(a2,1,a[i-1],a[i]-a[i-1]);
			}
			else
			{
				add(a1,a[i-1]+1,m,-1);
				add(a2,a[i-1]+1,m,m+a[i]+1);
				add(a1,1,a[i],-1);
				add(a2,1,a[i],a[i]+1);
				add(a2,a[i]+1,a[i-1],a[i]+m-a[i-1]);
			}
		}
	}
	for(i=1;i<=m;i++)
	{
		a1[i]+=a1[i-1];
		a2[i]+=a2[i-1];
	}
	ll ans=0x7fffffffffffffffll;
	for(i=1;i<=m;i++)
		ans=min(ans,a1[i]*i+a2[i]);
	printf("%lld\n",ans);
	return 0;
}