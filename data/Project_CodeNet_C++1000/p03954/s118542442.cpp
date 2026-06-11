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

const int N=200000+10;

int n,a[N];

inline int check(int mid) {
    for (re int i=0;i<n-1;++i) {
        if (a[n-i]<mid&&a[n-i-1]<mid) return 0;
        if (a[n+i]<mid&&a[n+i+1]<mid) return 0;
        if (a[n-i]>=mid&&a[n-i-1]>=mid) return 1;
        if (a[n+i]>=mid&&a[n+i+1]>=mid) return 1;
    }
    return a[1]<mid?0:1;
}

int main() {
    n=read();
    for (re int i=1;i<n<<1;++i) a[i]=read();
    int L=1,R=(n<<1)-1;
    while (L<R) {
        int mid=(L+R+1)>>1;
        if (check(mid)) L=mid;
        else R=mid-1;
    }
    printf("%d\n",L);
    return 0;
}
