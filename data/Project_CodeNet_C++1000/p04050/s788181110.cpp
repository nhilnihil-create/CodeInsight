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

int n,m,top;
int a[N],o[N];

int main() {
    n=read(),m=read();
    for (re int i=1;i<=m;++i) a[i]=read();
    for (re int i=1;i<=m;++i)
        if (a[i]&1) o[++top]=i;
    if (top>2) { puts("Impossible"); return 0; }
    if (top>0) swap(a[1],a[o[1]]);
    if (top>1) swap(a[m],a[o[2]]);
    if (m==1) {
        if (a[1]==1) printf("1\n1\n1\n");
        else printf("%d\n2\n1 %d\n",a[1],a[1]-1);
    } else {
        for (re int i=1;i<=m;++i) printf("%d ",a[i]); puts("");
        ++a[1],--a[m]; if (!a[m]) --m;
        printf("%d\n",m);
        for (re int i=1;i<=m;++i) printf("%d ",a[i]); puts("");
    }
    return 0;
}
