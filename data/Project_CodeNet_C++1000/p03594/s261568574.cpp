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

const char s[5]="RYGB";

int main() {
    int n=read(),m=read(),k=read();
    for (re int i=1;i<=n;++i) {
        for (re int j=1;j<=m;++j) {
            int x=((i+j)/k)&1,y=((i-j+m)/k)&1;
            putchar(s[2*x+y]);
        }
        puts("");
    }
    return 0;
}
