#include <bits/stdc++.h>
using namespace std;
#define N 250010
#define halt return puts("No"),0
inline int read() {
    int x=0;
    char ch=getchar();
    while (!isdigit(ch)) ch=getchar();
    while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x;
}
int p[N],c[N],a[N];
int main() {
    int n=read();
    for (int i=1;i<=n;i++) p[i]=read();
    for (int i=1;i<=n*n;i++) {
        for (int j=1;j<=n;j++) if (p[j]==i) {
            if ((++c[j])!=j) halt; a[i]=j; break;
        }
        if (a[i]) continue;
        int Min=0;
        for (int j=1;j<=n;j++)
            if (c[j]<j-1 && (!Min || p[j]<p[Min])) Min=j;
        if (Min) {c[a[i]=Min]++;continue;}
        for (int j=1;j<=n;j++) 
            if (c[j]<n && p[j]<i) {c[a[i]=j]++;break;}
        if (!a[i]) halt;
    }
    puts("Yes");
    for (int i=1;i<=n*n;i++) printf("%d ",a[i]);
    return 0;
}