#include<cstdio>
#include<cctype>

#define maxn 2222
#define mod 1000000007

inline int read(){
	int r=0,f=0;
	char c;
	while(!isdigit(c=getchar()))f|=(c=='-');
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?-r:r;
}

inline long long qpow(long long a,int b){
	long long ans=1;
	for(;b;b>>=1){
		if(b&1)(ans*=a)%=mod;
		(a*=a)%=mod;
	}
	return ans;
}

int n,k;

long long frac[maxn*maxn],invf[maxn*maxn],f[maxn][maxn];

inline long long C(int n,int m){
	return frac[n]*invf[m]%mod*invf[n-m]%mod;
}

int main(){
	n=read(),k=read();
	if(k==1)return puts("1"),0;
	frac[0]=1;
	for(int i=1;i<=n*k;i++)
		frac[i]=frac[i-1]*i%mod;
	invf[n*k]=qpow(frac[n*k],mod-2);
	for(int i=n*k;i>=1;i--)
		invf[i-1]=invf[i]*i%mod;
	for(int i=1;i<=n;i++)f[i][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i][j]=(f[i-1][j]+f[i][j-1]*(n-j+1)%mod*C(n*k-i-1-(j-1)*(k-1),k-2)%mod)%mod;
	printf("%lld\n",f[n][n]);
	return 0;
}