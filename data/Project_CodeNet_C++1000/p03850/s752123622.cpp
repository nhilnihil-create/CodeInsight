#include<cstdio>
#include<algorithm>
#define MAXN 100006
#define INF 23333333333333333
using namespace std;
int n,r[MAXN];
long long a[MAXN],sum[MAXN],ans=-INF;
char op[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		if(i==1) scanf("%lld",&a[i]);
		else scanf(" %c %lld",&op[i],&a[i]);
	}
	int last=n+1;
	for(int i=n;i>=1;i--)
	{
		sum[i]=sum[i+1]+a[i];
		r[i]=last;
		if(op[i]=='-') last=i;
	}
	long long sumlast=a[1];
	for(int i=2;i<=n;i++)
	{
		if(op[i]=='-') ans=max(ans,sumlast+sum[r[i]]*2-sum[i]);
		if(op[i]=='+') sumlast+=a[i];
		else sumlast-=a[i];
	}
	printf("%lld",max(ans,sumlast));
}