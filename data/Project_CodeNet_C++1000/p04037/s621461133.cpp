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

int n,a[N];

int main() {
    n=read();
    for (re int i=1;i<=n;++i) a[i]=read();
    sort(a+1,a+n+1,greater<int>());
    for (re int i=1;i<=n;++i) {
        if (i+1>a[i+1]) {
            int u=a[i]-i,r=0;
            while (i+r<n&&a[i+r+1]==i) ++r;
            if ((u&1)||(r&1)) puts("First");
            else puts("Second");
            return 0;
        }
    }
    return 0;
}
