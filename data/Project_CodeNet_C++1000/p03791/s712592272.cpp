#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL mod=1000000007;
LL n,ans=1,a[120000];

int main(){
	scanf("%lld",&n);
	for (LL i=1;i<=n;++i) scanf("%lld",a+i);
	for (LL i=1,j=1;i<=n;++i){
		for (;j<=n&&a[j]>=(j-i+1)*2-1;++j);
		ans=ans*(j-(j>n)-i+1)%mod;
	}
	printf("%lld\n",ans);
	
	return 0;
}
			