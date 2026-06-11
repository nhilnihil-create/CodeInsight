#include<cstdio>
typedef long long ll;
const int mod=1000000007;
int N,K,f[2010][2010];
ll fac[4000010],ifac[4000010];
ll inv(int a,int p=mod){return a==1?1:(1+p*(a-inv(p%a,a)))/a%p;}
ll C(int n,int m){return n>=0&&m<=n?fac[n]*ifac[m]%mod*ifac[n-m]%mod:0;}
int main(){
	scanf("%d%d",&N,&K);
	if(K==1)puts("1");
	else{
		for(int i=*fac=1;i<=N*K;i++)fac[i]=fac[i-1]*i%mod;
		ifac[N*K]=inv(fac[N*K]);
		for(int i=N*K;i;i--)ifac[i-1]=ifac[i]*i%mod;
		f[1][0]=f[1][1]=1;
		for(int i=2;i<=N;i++){
			for(int j=N;j;j--)
				f[i][j]=(f[i][j+1]+f[i-1][j-1]*C(i*K-j-1,K-2))%mod;
			f[i][0]=f[i][1];
		}
		int ans=f[N][0]*fac[N]%mod;
		printf("%d\n",ans);
	}
}