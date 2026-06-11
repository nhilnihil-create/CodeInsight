//AtCoder-agc002F
#include <cstdio>
#define rg register

const int N=2018,M=N*N,p=1e9+7;
int inv[M],fac[M],f[N][N];
int n,m;

template <typename _Tp> inline void pls(_Tp&A,_Tp B){A=A+B<p?A+B:A+B-p;}

inline int qpow(int A,int B){
	int res(1);while(B){
		if(B&1)res=1ll*res*A%p;
		A=1ll*A*A%p;B>>=1;
	}return res;
}

void prework(){
	inv[0]=inv[1]=fac[0]=fac[1]=1;
	for(rg int i=2;i<M;++i)fac[i]=1ll*fac[i-1]*i%p;
	inv[M-1]=qpow(fac[M-1],p-2);
	for(rg int i=M-2;i;--i)inv[i]=1ll*inv[i+1]*(i+1)%p;
}

inline int c(int nn,int mm){return 1ll*fac[nn]*inv[mm]%p*inv[nn-mm]%p;}

int main(){
	prework();scanf("%d%d",&n,&m);
	if(m==1){puts("1");return 0;}
	f[0][0]=1;
	for(rg int i=1;i<=n;++i){
		pls(f[i][0],(int)(1ll*f[i-1][0]*c(i*m-i-1,m-2)%p));
		for(rg int j=1;j<=i;++j){
			f[i][j]=f[i][j-1];
			pls(f[i][j],(int)(1ll*f[i-1][j]*c(i*m+j-i-1,m-2)%p));
		}
	}printf("%lld\n",1ll*f[n][n]*fac[n]%p);
	return 0;
}