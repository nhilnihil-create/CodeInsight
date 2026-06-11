#include<cstdio>

long long ans,a[8];

int main()
{
	for (int i=1; i<=7; ++i)
		scanf("%lld",&a[i]);
	ans=a[2];
	if (!a[1]||!a[4]||!a[5])
		ans+=a[1]/2*2+a[4]/2*2+a[5]/2*2;
	else
	{
		ans+=a[1]+a[4]+a[5];
		if (!(a[1]%2==a[4]%2&&a[4]%2==a[5]%2)) ans--;
	}
	printf("%lld",ans);
}