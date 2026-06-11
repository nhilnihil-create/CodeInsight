#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define LL long long
#define RG register
#define R RG int
using namespace std;
const LL N=2009,M=N*N,YL=1e9+7;
int f[N][N],fac[M],inv[M];
inline int fm(RG LL b){
    RG LL a=1;
    for(R k=YL-2;k;k>>=1,b=b*b%YL)
        if(k&1)a=a*b%YL;
    return a;
}
inline int C(R n,R m){
    if(n<0||m<0||n<m)return 0;
    return(LL)fac[n]*inv[m]%YL*inv[n-m]%YL;
}
int main(){
    R n,k,nk;
    scanf("%d%d",&n,&k);nk=n*k;
    if(k==1)return puts("1"),0;
    for(R i=fac[0]=1;i<=nk;++i)
        fac[i]=fac[i-1]*(LL)i%YL;
    inv[nk]=fm(fac[nk]);
    for(R i=nk;i;--i)
        inv[i-1]=inv[i]*(LL)i%YL;
    f[0][0]=1;
    for(R i=1;i<=n;++i)
        for(R j=f[i][0]=1;j<=i;++j)
            f[i][j]=(f[i-1][j]+(LL)f[i][j-1]*(n-j+1)%YL*C(n-i+(n-j+1)*(k-1)-1,k-2))%YL;
    printf("%d\n",f[n][n]);
    return 0;
}