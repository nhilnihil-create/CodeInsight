// ===================================
//   author: M_sea
//   website: http://m-sea-blog.com/
// ===================================
#include <bits/stdc++.h>
#define re register
using namespace std;

inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

const int N=100+10;

int n,a[N],o[N];

int main() {
    n=read();
    for (re int i=1;i<=n;++i) ++o[a[i]=read()];
    int d=0;
    for (re int i=1;i<=n;++i) d=max(d,a[i]);
    if (d&1) {
        int flag=1;
        for (re int i=d;i>(d+1)/2;--i) if (o[i]<2) flag=0;
        if (o[(d+1)/2]!=2) flag=0;
        for (re int i=(d-1)/2;i;--i) if (o[i]) flag=0;
        puts(flag?"Possible":"Impossible");
    } else {
        int flag=1;
        for (re int i=d;i>d/2;--i) if (o[i]<2) flag=0;
        if (o[d/2]!=1) flag=0;
        for (re int i=d/2-1;i;--i) if (o[i]) flag=0;
        puts(flag?"Possible":"Impossible");
    }
    return 0;
}
