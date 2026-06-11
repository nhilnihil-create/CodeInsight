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

const int N=100000+10;

int n,L,Q;
int x[N],f[18][N];

int main() {
    n=read();
    for (re int i=1;i<=n;++i) x[i]=read();
    L=read();
    for (re int i=1;i<=n;++i) f[0][i]=upper_bound(x+1,x+n+1,x[i]+L)-x-1;
    for (re int i=1;i<=17;++i)
        for (re int j=1;j<=n;++j)
            f[i][j]=f[i-1][f[i-1][j]];
    Q=read();
    while (Q--) {
        int x=read(),y=read(),ans=0;
        if (x>y) swap(x,y);
        for (re int i=17;~i;--i)
            if (f[i][x]<y) ans|=(1<<i),x=f[i][x];
        printf("%d\n",ans+1);
    }
    return 0;
}
