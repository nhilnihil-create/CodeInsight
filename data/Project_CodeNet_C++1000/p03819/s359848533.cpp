#include <bits/stdc++.h>
using namespace std;
#define N 300010
struct TreeArray {
    int f[N];
    #define lowbit(x) ((x)&(-x))
    inline void add(int k,int dat) {
        while (k<N) f[k]+=dat,k+=lowbit(k);
    }
    inline int sum(int k) {
        int ans=0;
        while (k) ans+=f[k],k-=lowbit(k);
        return ans;
    }
    inline void add(int l,int r,int dat) {
        add(l,dat),add(r+1,-dat);
    }
}T;
inline int read() {
    int x=0;
    char ch=getchar();
    while (!isdigit(ch)) ch=getchar();
    while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x;
}
struct node {
    int l,r;
}a[N];
inline int cmp(node a,node b) {
    return a.r-a.l<b.r-b.l;
}
int main() {
    int n=read(),m=read(),p=1;
    for (int i=1;i<=n;i++) a[i].l=read(),a[i].r=read();
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=m;i++) {
        while (p<=n && a[p].r-a[p].l+1<=i) T.add(a[p].l,a[p].r,1),++p;
        // puts("qwq");
        int ans=n-p+1;
        for (int j=0;j<=m;j+=i) ans+=T.sum(j);
        printf("%d\n",ans);
    }
    return 0;
}