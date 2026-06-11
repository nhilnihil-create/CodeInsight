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
typedef long long ll;

inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

const int N=2000+10;

int n,x;
int a[N],w[N];

int main() {
    n=read(),x=read();
    for (re int i=0;i<n;++i) a[i]=read();
    memset(w,0x3f,sizeof(w)); ll ans=1e18;
    for (re int i=0;i<n;++i) {
        for (re int j=0;j<n;++j) w[j]=min(w[j],a[(j-i+n)%n]);
        ll now=0;
        for (re int j=0;j<n;++j) now+=w[j];
        ans=min(now+1ll*i*x,ans);
    }
    printf("%lld\n",ans);
    return 0;
}
