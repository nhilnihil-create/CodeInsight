#include<cstdio>
#define mod 1000000007
#define int long long
int f[2010][2010],fac[4000100],inv[4000100],n,k;
int quickpow(int x,int y){
	if(y==0)return 1;
	if(y%2==0)return quickpow(x*x%mod,y/2);
	if(y%2==1)return quickpow(x*x%mod,y/2)*x%mod;
}
int C(int x,int y){
	if(x<y||y<0)return 0;
	if(x==y||y==0)return 1;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
signed main(){
	scanf("%lld%lld",&n,&k);
	if(k==1){
		puts("1");
		return 0;
	}
	fac[0]=1;
	for(int i=1;i<=n*k;i++)
		fac[i]=fac[i-1]*i%mod;
	inv[n*k]=quickpow(fac[n*k],mod-2);
	for(int i=n*k-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j>=0;j--){
            if(j)(f[i][j]+=f[i-1][j-1]*C(k*i-j-1,k-2)%mod)%=mod;
            f[i][j]=(f[i][j]+f[i][j+1])%mod;	
		}
	printf("%lld\n",fac[n]*f[n][0]%mod);
}