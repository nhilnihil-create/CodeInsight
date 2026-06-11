#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
int a[10];
LL ans;
int main()
{
	for(int i=1;i<=7;i++)
		scanf("%d",&a[i]);
	ans=a[2];
	if(!a[1]||!a[4]||!a[5]) printf("%lld\n",ans+a[1]/2*2+a[4]/2*2+a[5]/2*2);
	else if(a[1]%2==a[4]%2&&a[4]%2==a[5]%2) printf("%lld\n",ans+a[1]+a[4]+a[5]);
	else printf("%lld\n",ans+a[1]+a[4]+a[5]-1);
}