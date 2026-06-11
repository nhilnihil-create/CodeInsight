#include <bits/stdc++.h>
#define LL long long
#define N 1000010
#define M 1000000007
LL n,f[N],sum;
int main()
{
	scanf("%lld",&n);
	f[n]=n,f[n-1]=(LL)n*n%M;
	for(LL i=n-2;i>=1;--i)
	{
		sum=(sum+f[i+3])%M;
		f[i]=f[i+1];
		f[i]=(f[i]+(LL)(n-1)*(n-1)%M)%M;
		f[i]=(f[i]+sum)%M;
		f[i]=(f[i]+i+1)%M;
	}
	printf("%lld\n",f[1]);
	return 0;
}