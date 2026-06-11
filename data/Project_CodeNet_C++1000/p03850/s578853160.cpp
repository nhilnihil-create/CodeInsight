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
ll upmax(ll &a,ll b)
{
	if(b>a)
	{
		a=b;
		return 1;
	}
	return 0;
}
int op[1000010];
int a[1000010];
ll f[1000010][5];
int main()
{
	char s[2];
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		if(i>1)
		{
			scanf("%s",s);
			if(s[0]=='+')
				op[i]=1;
			else
				op[i]=2;
		}
		else
			op[i]=1;
		scanf("%d",&a[i]);
	}
	memset(f,0x80,sizeof f);
	f[0][0]=0;
	for(i=0;i<=n;i++)
	{
		upmax(f[i][1],f[i][2]);
		upmax(f[i][0],f[i][1]);
		if(i==n)
			continue;
		if(op[i+1]==1)
		{
			upmax(f[i+1][0],f[i][0]+a[i+1]);
			upmax(f[i+1][1],f[i][1]-a[i+1]);
			upmax(f[i+1][2],f[i][2]+a[i+1]);
		}
		else
		{
			upmax(f[i+1][0],f[i][0]-a[i+1]);
			upmax(f[i+1][1],f[i][0]-a[i+1]);
			upmax(f[i+1][1],f[i][1]+a[i+1]);
			upmax(f[i+1][2],f[i][1]+a[i+1]);
			upmax(f[i+1][2],f[i][2]-a[i+1]);
		}
	}
	printf("%lld\n",f[n][0]);
	return 0;
}