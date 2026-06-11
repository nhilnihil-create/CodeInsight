#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n;
ll f[1000005];
int main(){
	scanf("%d",&n);
	f[1]=n;
	f[0]=1;
	ll sum=0;
	for(int i=2;i<=n;i++){
		f[i]=(sum+f[i-1]+1LL*(n-1)*(n-1)+(n-i+1))%mod;
		sum=(sum+f[i-2])%mod;
	}
	printf("%lld",f[n]);
	return 0;
}