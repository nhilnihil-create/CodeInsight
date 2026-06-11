#include<cstdio>
long long n,f[1000001]={1,1,1,2,4,7},g[1000001]={1,2,3,5,9,16},sumk=6;
int main(){
	scanf("%d",&n);
	if(n==1) {puts("1"); return 0;}
	if(n==2) {puts("4"); return 0;}
	if(n==3) {puts("15"); return 0;}
	for(int i=6;i<=n;++i){
		sumk+=g[i-3];
		sumk%=1000000007;
		f[i]=sumk+1;
		g[i]=(g[i-1]+f[i])%1000000007;
	}
//	for(int i=0;i<=n;++i) printf("%d ",f[i]); puts("");
//	for(int i=0;i<=n;++i) printf("%d ",g[i]); puts("");
	long long ans=g[n-2]*(n-1)%1000000007+1+((n-1)*g[n-2]%1000000007+f[n-1])*(n-1)%1000000007;
	ans%=1000000007;
	printf("%d",ans);
	return 0;
}