#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#define inf 2147483647
#define eps 1e-9
#define mod 1000000007
using namespace std;
typedef long long ll;
ll n,pre=1,ans=0,f[1000001];
int main(){
	scanf("%lld",&n);
	f[0]=1;
	for(int i=1;i<=n;i++){
		if(i>=2)f[i]-=f[i-2];
		f[i]=(f[i]+pre+mod)%mod;
		pre=(pre+f[i])%mod;
	}
	for(int i=0;i<=n-2;i++){
		ans=(ans+f[i]*(n-1)%mod*(n-1)%mod+f[i]*(i+1)%mod)%mod;
	}
	ans=(ans+f[n-1]*(n-1)%mod+f[n])%mod;
	printf("%lld",ans);
	return 0;
}