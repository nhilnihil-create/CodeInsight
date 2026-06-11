#include<iostream>
#include<cstdio>
#include<cstdlib>
#define re register
#define LL long long
#define N 2005
#define Maxn 4000000
using namespace std;
const int Mod=1e9+7;
int n,k;
LL f[N][N],fac[Maxn+5],inv_fac[Maxn+5];
inline LL C(int n,int m){ return (((fac[m]*inv_fac[n])%Mod)*inv_fac[m-n])%Mod; }
LL power(LL x,int P){
    LL ans=1,m=x;
    while(P){
        if(P&1) (ans*=m)%=Mod;
        P>>=1;(m*=m)%=Mod;
    }
    return ans;
}
int main(){
    scanf("%d%d",&n,&k);
    if(k==1){ printf("%d\n",1); return 0; }
    fac[0]=1; for(re int i=1;i<=Maxn;++i) fac[i]=(fac[i-1]*i)%Mod;
    inv_fac[Maxn]=power(fac[Maxn],Mod-2); for(re int i=Maxn-1;i>=0;--i) inv_fac[i]=(inv_fac[i+1]*(i+1))%Mod;
    f[0][0]=1;
    for(re int i=1;i<=n;++i){
        for(re int j=0;j<=i;++j){
            f[i][j]=f[i-1][j];
            if(!j) continue;
            (f[i][j]+=f[i][j-1]*(n-j+1)%Mod*C(k-2,n-i+(n-j+1)*(k-1)-1)%Mod)%=Mod;
        }
    }
    printf("%lld\n",f[n][n]);
    return 0;
}