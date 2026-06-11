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

const int N=100+10;

vector<int> c;

int main() {
    int n=read(),x=read();
    if (x==1||x==2*n-1) puts("No"); 
    else { puts("Yes");
        if (n==2) printf("1\n2\n3\n");
        else if (x==2) {
            for (re int i=5;i<=2*n-1;++i) c.push_back(i);
            int p=0;
            for (re int i=1;i<=n-2;++i) printf("%d\n",c[p++]);
            printf("3\n2\n1\n4\n");
            for (re int i=n+3;i<=2*n-1;++i) printf("%d\n",c[p++]);
        } else {
            for (re int i=1;i<=x-3;++i) c.push_back(i);
            for (re int i=x+2;i<=2*n-1;++i) c.push_back(i);
            int p=0;
            for (re int i=1;i<=n-2;++i) printf("%d\n",c[p++]);
            printf("%d\n%d\n%d\n%d\n",x-1,x,x+1,x-2);
            for (re int i=n+3;i<=2*n-1;++i) printf("%d\n",c[p++]);
        }
    }
    return 0;
}
