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
typedef long long ll;

inline ll read() {
    ll X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

inline ll calc(ll n,ll x) {
    if (n%x==0) return n*2-x;
    return n/x*x*2+calc(x,n%x);
}

int main() {
    ll n=read(),x=read();
    printf("%lld\n",calc(n-x,x)+n);
    return 0;
}
