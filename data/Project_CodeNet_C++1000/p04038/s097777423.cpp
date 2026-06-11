#include<cstdio>
const int N=2007,P=1000000007;
int n,m,k,fac[N*N],ifac[N*N],f[N][N];
void inc(int&a,int b){a+=b-P,a+=a>>31&P;}
void mul(int&a,int b){a=1ll*a*b%P;}
int C(int n,int m){return 1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;}
int pow(int a,int b){int r=1;for(;b;b>>=1,mul(a,a))if(b&1)mul(r,a);return r;}
int main()
{
    scanf("%d%d",&n,&k),m=n*k,f[0][0]=1;
    if(k==1) return puts("1"),0;
    fac[0]=1;for(int i=1;i<=m;++i)mul(fac[i]=fac[i-1],i);
    ifac[m]=pow(fac[m],P-2);for(int i=m;i;--i)mul(ifac[i-1]=ifac[i],i);
    for(int i=0,z=k-1;i<=n;++i,z+=k-1)
	for(int j=0;j<=i;++j)
	    inc(f[i+1][j],1ll*f[i][j]*C(z+j-1,k-2)%P),inc(f[i][j+1],f[i][j]);
    mul(f[n][n],fac[n]),printf("%d",f[n][n]);
}
