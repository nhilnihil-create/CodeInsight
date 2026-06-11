#include<cstdio>
#include<cstring>
typedef long long LL;
const int md=1e9+7,N=16384;
int fac[N],iv[N],n,c[5002],dp[5002],g[5002],h[5002],s[5002];
char v[N];
inline int C(int n,int m){return(LL)fac[n]*iv[m]%md*iv[n-m]%md;}
inline int pow(int a,int b){
	int ret=1;
	for(;b;b>>=1,a=(LL)a*a%md)if(b&1)ret=(LL)ret*a%md;
	return ret;
}
void PW(int b,int n){
	static int A[5002];
	*dp=1;
	for(;b;b>>=1){
		if(b&1){
			memset(A,0,sizeof A);
			for(int i=0;i<=n;++i)for(int j=0;j<=i;++j)
			A[i]=(A[i]+(LL)dp[j]*c[i-j])%md;
			memcpy(dp,A,sizeof A);
		}
		memset(A,0,sizeof A);
		for(int i=0;i<=n;++i)for(int j=0;j<=i;++j)
		A[i]=(A[i]+(LL)c[j]*c[i-j])%md;
		memcpy(c,A,sizeof A);
	}
}
int main(){
	scanf("%d%s",&n,v);
	int L=strlen(v),k=n-L>>1;
	for(int i=*fac=1;i<=2*n;++i)fac[i]=(LL)fac[i-1]*i%md;
	iv[2*n]=pow(fac[2*n],md-2);
	for(int i=2*n-1;~i;--i)iv[i]=(i+1LL)*iv[i+1]%md;
	for(int i=0,w=1;i<=k;++i,w=w*2>=md?w*2-md:w*2)
	c[i]=(LL)C(2*i,i)*iv[i+1]%md*fac[i]%md*w%md;
	PW(L+1,k);
	h[0]=g[0]=1;
	for(int i=1;i<=2*k+1;++i){
		memset(s,0,sizeof s);
		for(int j=1;j<=2*k+1;++j)s[j]=g[j-1]*2%md;
		for(int j=0;j<2*k+1;++j)s[j]=(s[j]+g[j+1])%md;
		s[0]=(s[0]+g[0])%md;
		h[i]=s[0];
		memcpy(g,s,sizeof s);
	}
	int ans=0;
	for(int i=0;i<=k;++i){
		int sy=n-2*i-L;
		int ch=(sy==0)?1:h[sy-1];
		ans=(ans+(LL)ch*dp[i])%md;
	}
	printf("%d\n",ans);
	return 0;
}