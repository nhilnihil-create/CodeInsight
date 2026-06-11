// ===================================
//   author: M_sea
//   website: http://m-sea-blog.com/
// ===================================
#include <bits/stdc++.h>
#define re register
using namespace std;
typedef long long ll;

inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

const int N=200000+10;

int n,a[N];
int L[N],R[N];
int sta[N],top=0;

int main() {
    n=read();
    for (re int i=1;i<=n;++i) a[i]=read();
    a[0]=0,sta[top=1]=0;
    for (re int i=1;i<=n;++i) {
        while (top&&a[i]<a[sta[top]]) --top;
        L[i]=sta[top],sta[++top]=i;
    }
    a[n+1]=0,sta[top=1]=n+1;
    for (re int i=n;i;--i) {
        while (top&&a[i]<a[sta[top]]) --top;
        R[i]=sta[top],sta[++top]=i;
    }
    ll ans=0;
    for (re int i=1;i<=n;++i) ans+=1ll*a[i]*(i-L[i])*(R[i]-i);
    printf("%lld\n",ans);
    return 0;
}
