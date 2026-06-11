#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
const int mod=1e9+7;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
int n,m,f[N][N],fac[N*N],inv[N*N],ifac[N*N];
int C(int n,int m) {
    if(n<0||m<0||n<m) return 0;
    return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main() {
    cin>>n>>m;int N=n*m;
    if(m==1) return puts("1"),0;
    fac[0]=1;for(int i=1;i<=N;i++) fac[i]=1ll*fac[i-1]*i%mod;
    inv[1]=1;for(int i=2;i<=N;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    ifac[0]=1;for(int i=1;i<=N;i++) ifac[i]=1ll*ifac[i-1]*inv[i]%mod;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++) f[i][j]=(f[i-1][j]+1ll*f[i][j-1]%mod*(n-j+1)%mod*C(n-i+(n-j+1)*(m-1)-1,m-2)%mod)%mod;
    printf("%d\n",f[n][n]);
    return 0;
}
//orzgzy
//鸡贼明年进队超稳
