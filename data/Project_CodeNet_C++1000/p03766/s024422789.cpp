#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long LL;
const LL mo=1e9+7;
const int N=1e6;
int n;
LL ans=0,f[N+10],sum[N+10];
int main() {
    scanf("%d",&n);
    f[0]=f[1]=f[2]=1;
    sum[0]=1;
    sum[1]=2;
    sum[2]=3;
    for (int i=3;i<n;i++) {
        f[i]=(f[i-1]+sum[i-3])%mo;
	sum[i]=(sum[i-1]+f[i])%mo;	
    }
    for (int i=0;i<n-1;i++) {
	ans=(ans+f[i]*(n-1)%mo*(n-1))%mo;
	int l=max(2,n-i-1);
	ans=(ans+(n-l+1)*f[i])%mo;
    }
    ans=((ans+f[n-1]*n)%mo+mo)%mo;
    printf("%lld\n",ans);
    return 0;
}
