// ===================================
//   author: M_sea
//   website: http://m-sea-blog.com/
// ===================================
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#define re register
using namespace std;

inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

const int N=200000+10;
const int mod=1e9+7;

inline int qpow(int a,int b) { int c=1;
    for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) c=1ll*c*a%mod;
    return c;
}

int fac[N],ifac[N];
inline void init(int n) {
    fac[0]=1;
    for (re int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
    ifac[n]=qpow(fac[n],mod-2);
    for (re int i=n;i;--i) ifac[i-1]=1ll*ifac[i]*i%mod;
}
inline int calc(int n,int m) {
    return 1ll*fac[n+m]*ifac[n]%mod*ifac[m]%mod;
}

int H,W,A,B;
int main() {
    init(200000);
    H=read(),W=read(),A=read(),B=read();
    int ans=0;
    for (re int x=H-A,y=B+1;x>=1&&y<=W;--x,++y)
        ans=(ans+1ll*calc(x-1,y-1)*calc(H-x,W-y))%mod;
    printf("%d\n",ans);
    return 0;
}
