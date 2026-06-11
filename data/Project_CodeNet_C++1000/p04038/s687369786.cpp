#include<cstdio>
using namespace std;
const int maxn=2e3+2;
const int maxm=4e6+2;
const int mod=1e9+7;
int n,m;
int fac[maxm],inv[maxm],fv[maxm];
void init(){
	fac[0]=fac[1]=inv[1]=fv[0]=fv[1]=1;
	for (int i=2;i<=maxm;i++){
		fac[i]=1LL*fac[i-1]*i%mod;
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
		fv[i]=1LL*fv[i-1]*inv[i]%mod;
	}
}
int Com(int x,int y){return 1LL*fac[x]*fv[y]%mod*fv[x-y]%mod;}
int dp[maxn];
void DP(){
	dp[0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			dp[j]=(dp[j]+1LL*dp[j-1]%mod*(n-j+1)%mod*Com(n*m-i-(j-1)*(m-1)-1,m-2)%mod)%mod;
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	if (m==1){
		printf("1");
		return 0;
	}
	DP();
	printf("%d",dp[n]);
	return 0;
}