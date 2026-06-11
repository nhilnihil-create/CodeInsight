#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define N 1000011
#define LL long long
LL n;
LL f[N],sum[N];
int main(){
	scanf("%lld",&n);
	f[0]=1;
	f[1]=n;f[2]=n*n%MOD;
	sum[1]=f[1]+1;sum[2]=(f[1]+f[2]+1)%MOD;sum[0]=f[0]=1;
	for(int i=3;i<=n;i++){
		f[i]=((f[i-1]+sum[i-3])%MOD+(n-1)*(n-1)%MOD+(n-i+1))%MOD;
		sum[i]=(sum[i-1]+f[i])%MOD;
	}
	printf("%lld\n",f[n]);
}
