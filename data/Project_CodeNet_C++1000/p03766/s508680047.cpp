#include<cstdio>
long long n,f[1000001],sum;
int main()
{
	scanf("%lld",&n);
	f[1]=n;f[2]=n*n;
	for(int i=3;i<=n;++i){
		f[i]=(f[i-1]+(n-i+2)*f[1]+sum)%1000000007;
		sum=(sum+f[i-2]+n-1)%1000000007;
	}
	printf("%lld\n",f[n]);
	return 0;
}