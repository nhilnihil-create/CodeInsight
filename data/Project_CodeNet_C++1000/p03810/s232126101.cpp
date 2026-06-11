#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
int n,i,j,t=1,a[100005];
int gcd(int a,int b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
signed main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	while(1)
	{
		for(i=1,j=0;i<=n;++i)
		{
			if(a[i]==1)
				break;
			if(a[i]%2==0)
				++j;
		}
		if(i<=n)
		{
			for(i=1,j=0;i<=n;++i)
				j=(j+a[i]-1)%2;
			if(j)
				printf(t?"First":"Second");
			else
				printf(t?"Second":"First");
			return 0;
		}
		if(j==0)
		{
			printf(t?"Second":"First");
			return 0;
		}
		if(j%2==1)
		{
			printf(t?"First":"Second");
			return 0;
		}
		if(n-j>=2)
		{
			printf(t?"Second":"First");
			return 0;
		}
		for(i=1;i<=n;++i)
			if(a[i]&1)
			{
				--a[i];
				break;
			}
		j=a[1];
		for(i=2;i<=n;++i)
			j=gcd(j,a[i]);
		for(i=1;i<=n;++i)
			a[i]/=j;
		t=1-t;
	}
	return 0;
}
