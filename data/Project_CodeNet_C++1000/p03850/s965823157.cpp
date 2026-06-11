#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100010
#define INF 0x3FFFFFFF
#define LL long long
int a[MAXN],n;
LL sum=0,pre[MAXN],ans=-INF;
bool b[MAXN];
char s[10];
int main()
{
	scanf("%d",&n);
	scanf("%d",&a[1]);
	for(int i=2;i<=n;i++)
	{
		scanf("%s%d",s,&a[i]);
		if(s[0]=='-') b[i]=1;
	}
	for(int i=n;i>0;i--)
		pre[i]=pre[i+1]+a[i];
	int ls=1;
	while(b[ls]==0&&ls<=n)
	{
		sum+=a[ls];
		ls++;
	}
	while(ls<=n)
	{
		int ls1=ls+1;
		LL sum1=0;
		while(ls1<=n&&b[ls1]==0)
		{
			sum1+=a[ls1];
			ls1++;
		}
		if(ls1<=n) ans=max(ans,sum-sum1-a[ls]+pre[ls1]);
		sum-=a[ls],sum+=sum1;
		ls=ls1;
	}
	ans=max(ans,sum);
	printf("%lld\n",ans);
}