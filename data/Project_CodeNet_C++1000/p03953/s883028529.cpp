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
#define int long long
using namespace std;

inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

const int N=100000+10;

int n,m,k;
int x[N],a[N];
int p[N],vis[N],sta[N],top;
int ans[N];

signed main() {
    n=read();
    for (re int i=1;i<=n;++i) x[i]=read();
    m=read(),k=read();
    for (re int i=1;i<=m;++i) a[i]=read();
    for (re int i=n;i;--i) x[i]-=x[i-1];
    for (re int i=1;i<=n;++i) p[i]=i;
    for (re int i=1;i<=m;++i) swap(p[a[i]],p[a[i]+1]);
    for (re int i=1;i<=n;++i) {
        if (vis[i]) continue;
        top=0;
        for (re int j=i;!vis[j];j=p[j]) sta[++top]=j,vis[j]=1;
        for (re int j=1;j<=top;++j) ans[sta[j]]=x[sta[(j+k-1)%top+1]];
    }
    for (re int i=1;i<=n;++i) ans[i]+=ans[i-1];
    for (re int i=1;i<=n;++i) printf("%.1lf\n",1.*ans[i]);
    return 0;
}
