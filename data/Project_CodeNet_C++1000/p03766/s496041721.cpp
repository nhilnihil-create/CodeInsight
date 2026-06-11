#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int n,f[1000005]={1},s[1000005]={1},ans=0;
signed main(){
	scanf("%lld",&n);
	if(n==1)return puts("1"),0;
	for(int i=1;i<n;i++){
		f[i]=f[i-1]+(i>=3?s[i-3]:0);
		s[i]=s[i-1]+f[i];
		f[i]%=mod;
		s[i]%=mod;
		//cout<<f[i]<<endl;
		if(i<n-1)ans+=((n-1)*(n-1)%mod+min(i+2,n-1))*f[i],ans%=mod;
	}
	printf("%lld\n",(ans+n*f[n-1]%mod+(n-1)*(n-1)+1+(n>2))%mod);
}