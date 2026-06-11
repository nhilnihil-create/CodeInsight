#include <cstdio>
const int mo=1000000007;
int sum[1000005];
int main(){
	int n,ans;
	scanf("%d",&n);
	ans=1ll*n*n%mo;
	sum[1]=n;sum[2]=(ans+n)%mo;
	for (int i=3;i<=n;i++){
		ans=(ans+sum[i-3]+1ll*n*(n-1)-i+3)%mo;
		sum[i]=(sum[i-1]+ans)%mo;
	}
	printf("%d\n",ans);
}