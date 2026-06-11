#include <cstdio>
#define rg register

const int N=200001,p=1e9+7;
int fac[N],inv[N],n,a,W,H,A,B;

inline int c(int x,int y) {return 1ll*fac[x]*inv[y]%p*inv[x-y]%p;}

inline int qpow(int A,int B){int r=1;for(;B;B>>=1,A=1ll*A*A%p)if(B&1)r=1ll*r*A%p;return r;}
inline void pls(int&A,long long B){A=A+B<p?A+B:A+B-p;}
inline int max(int A,int B){return A>B?A:B;}

int main(){
	scanf("%d%d%d%d",&H,&W,&A,&B);
	int lim=max(H-A+B-2,W-B+H);
	fac[0]=inv[0]=1;
	for(rg int i=1;i<=lim;++i)fac[i]=1ll*fac[i-1]*i%p;
	inv[lim]=qpow(fac[lim],p-2);
	for(rg int i=lim-1;i;--i)inv[i]=1ll*inv[i+1]*(i+1)%p;
	for(rg int i=0;i<H-A;++i)
		pls(a,1ll*c(i+B-1,i)*c(W-B+H-i-2,W-B-1)%p);
	printf("%d\n",a);return 0;
}