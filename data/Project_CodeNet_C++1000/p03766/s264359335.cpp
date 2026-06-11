#include <iostream>
#include <cstdio>
#include <cstring>
#include <cassert>
typedef long long lint;
const int N=1e6+5;
const int mod=1e9+7;
int n,dp[N];

inline int nxi(FILE *fd=stdin){
	int x=0;
	char c;
	while((c=fgetc(fd))>'9'||c<'0');
	while(x=x*10-48+c,(c=fgetc(fd))>='0'&&c<='9');
	return x;
}

int main(){
	n=nxi();
	const int endless=(lint)(n-1)*(n-1)%mod;
	int pre=dp[0]=1,ans=0;
	for(int i=1; i<=n; ++i){
		int cur=(pre-(i>=2?dp[i-2]:0)+mod)%mod;
		if(i<n-1){
			ans=(ans+(lint)cur*(endless+(i+1)))%mod;
		}
		if(i==n-1){
			ans=(ans+(lint)cur*(n-1))%mod;
		}
		if(i==n){
			ans=(ans+cur)%mod;
		}
		pre=(pre+(dp[i]=cur))%mod;
	}
	printf("%d\n",(ans+endless+(n>1))%mod);
	return 0;
}
