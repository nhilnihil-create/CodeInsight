// ===================================
//   author: M_sea
//   website: http://m-sea-blog.com/
// ===================================
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#define re register
using namespace std;

inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

const int N=2000+10,L=N*N;
const int mod=1e9+7;
inline int qpow(int a,int b) {
    int c=1;
    for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) c=1ll*c*a%mod;
    return c;
}

int fac[L],ifac[L];
inline void init(int n) {
    fac[0]=1;
    for (re int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n]=qpow(fac[n],mod-2);
    for (re int i=n;i;--i) ifac[i-1]=1ll*ifac[i]*i%mod;
}
inline int C(int n,int m) {
    if (n<m) return 0;
    return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

int n,k,dp[N][N];

int main() {
    n=read(),k=read(); init(n*k);
    if (k==1) { puts("1"); return 0; }
    for (re int i=1;i<=n;++i) dp[i][0]=1;
    for (re int i=1;i<=n;++i)
        for (re int j=1;j<=i;++j)
            dp[i][j]=(dp[i-1][j]+1ll*dp[i][j-1]*(n-j+1)%mod*C(n*k-i-(j-1)*(k-1)-1,k-2))%mod;
    printf("%d\n",dp[n][n]);
    return 0;
}
