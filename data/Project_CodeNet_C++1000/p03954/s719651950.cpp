#include <iostream>
#include <cstdio>
#define N 1000050
#define INF (1<<30)

#define gc() getchar()

using namespace std;
int a[N],b[N],n;
inline int rd() {
    int x=0,f=1; char ch=gc();
    while (ch<'0'||ch>'9') ch=='-'?f*=-1:0,ch=gc();
    while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc();
    return x*f;
}

int go(int x) {
    for (int i=1;i<=2*n-1;i++) b[i] = a[i] >= x;
    int p = n % 2 == 0 , cur = INF;
    int ret = b[n] ^ p;
    for (int i=n-1;i>=1;i--) {
        if (b[i] == b[i+1] && n-i < cur) {
            cur = n-i;
            ret = b[i];
        } 
    }
    for (int i=n+1;i<=2*n-1;i++) {
        if (b[i] == b[i-1] && i-n < cur) {
            cur = i-n;
            ret = b[i];
        }
    }
    return ret;
}

int main() {
    n = rd();
    for (int i=1;i<=2*n-1;i++) a[i] = rd();
    int l = 1 , r = 2 * n - 1;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (go(mid)) l = mid; else r = mid - 1;
    }
    printf("%d\n",l);
    return 0;
}