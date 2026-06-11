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

int n,l,a[N];

int main() {
    n=read(),l=read();
    for (re int i=1;i<=n;++i) a[i]=read();
    int p,mx=0;
    for (re int i=1;i<n;++i)
        if (a[i]+a[i+1]>mx) mx=a[i]+a[i+1],p=i;
    if (mx<l) puts("Impossible");
    else {
        puts("Possible");
        for (re int i=1;i<p;++i) printf("%d\n",i);
        for (re int i=n-1;i>p;--i) printf("%d\n",i);
        printf("%d\n",p);
    }
    return 0;
}
