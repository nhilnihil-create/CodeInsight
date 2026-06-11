#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define inf (1LL<<60)
inline int read() {
    int x=0,f=1;
    char ch=getchar();
    while (!isdigit(ch)) {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x*f;
}
long long f[N][3];
int main() {
    int n=read();
    f[0][0]=0,f[0][1]=f[0][2]=-inf;
    for (int i=1;i<=n;i++) {
        int x=read();
        f[i][0]=max(f[i-1][0],f[i-1][1])+x;
        f[i][1]=max(f[i-1][1],f[i-1][2])-x;
        f[i][2]=f[i-1][2]+x;
        if (x<0) f[i][2]=max(f[i][2],f[i][1]),f[i][1]=max(f[i][1],f[i][0]);
    }
    cout<<max(f[n][0],max(f[n][1],f[n][2]))<<endl;
    return 0;
}