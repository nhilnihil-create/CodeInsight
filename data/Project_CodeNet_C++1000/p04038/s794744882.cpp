#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+11;
const int M=4e6+11;
const int mod=1e9+7;
int n,k,f[N][N],fac[M],ifac[M];
int read(){
    int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}
int qpow(int a,int b){
    int re=1;
    while(b){
        if(b&1) re=(re*a)%mod;
        b>>=1;a=a*a%mod;
    }return re;
}
int C(int a,int b){
    if(a<b) return 0;
    return fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}
signed main(){
    n=read(),k=read();
    if(k==1) return puts("1"),0;
    fac[0]=1;ifac[0]=1;f[0][0]=1;
    for(int i=1;i<=n*k;i++) fac[i]=fac[i-1]*i%mod;
    ifac[n*k]=qpow(fac[n*k],mod-2);
    for(int i=n*k-1;i;i--) ifac[i]=ifac[i+1]*(i+1)%mod;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++){
            if(i>=j) f[i][j]+=f[i-1][j];
            f[i][j]=(f[i][j]+f[i][j-1]*C((n-j+1)*(k-1)+n-i-1,k-2)%mod)%mod;
        }
    printf("%lld\n",f[n][n]*fac[n]%mod);
    return 0;
}