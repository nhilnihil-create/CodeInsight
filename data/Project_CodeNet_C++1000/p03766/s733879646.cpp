#include<cstdio>
const int md=1e9+7;
int n,ans,f[1000005],g[1000005];
int main(){
	scanf("%d",&n);
	ans=(n-1LL)*(n-1LL)%md;
	ans+=(n>2)+1;
	f[0]=g[0]=1;
	for(int i=1;i<n;++i){
		f[i]=(f[i-1]+((i>=3)?g[i-3]:0))%md,g[i]=(g[i-1]+f[i])%md;
		if(i<n-1)ans=(ans+((n-1LL)*(n-1)+i+1+(i!=n-2))%md*f[i])%md;else
		ans=(ans+1ll*n*f[i])%md;
	}
	printf("%d",ans);
	return 0;
}