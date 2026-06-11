#include<bits/stdc++.h>
using namespace std;
long long n,qs[200005],a,mn=1e18,sum=0;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		qs[i]=qs[i-1]+a;
		sum+=a;
	}
	for(int i=1;i<n;i++)
	{
		mn=min(mn,abs(qs[i]-(sum-qs[i])));
	}
	printf("%lld\n",mn);
}