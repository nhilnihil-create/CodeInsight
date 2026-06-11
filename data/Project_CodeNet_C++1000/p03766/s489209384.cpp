//It is made by M_sea
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

const int N=1000000+10;
const int mod=1e9+7;

int f[N];

int main() {
    int n=read();
    f[n]=n,f[n-1]=1ll*n*n%mod;
    for (re int i=n-2,s=0;i>=1;--i) {
        s=(s+f[i+3])%mod;
        f[i]=(s+i+1+1ll*(n-1)*(n-1)%mod+f[i+1])%mod;
    }
    printf("%d\n",f[1]);
    return 0;
}
