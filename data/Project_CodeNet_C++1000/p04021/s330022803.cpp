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

const int N=100000+10;

int n,a[N],b[N];

int main() {
    n=read();
    for (re int i=1;i<=n;++i) b[i]=a[i]=read();
    sort(b+1,b+n+1); int ans=0;
    for (re int i=1;i<=n;++i) {
        int x=lower_bound(b+1,b+n+1,a[i])-b;
        ans+=(x-i)&1;
    }
    printf("%d\n",ans>>1);
    return 0;
}
