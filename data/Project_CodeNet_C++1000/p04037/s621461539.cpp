
#include <bits/stdc++.h>
using namespace std;
int a[100005];
inline int read() {
    int x=0;
    char ch=getchar();
    while (!isdigit(ch)) ch=getchar();
    while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x;
}
int main() {
    int n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1,greater<int>());
    for (int i=1;i<=n;i++) {
        if (a[i+1]<=i && a[i]>=i) {
            int j=0;
            while (a[j+i+1]==i) j++;
            if ((a[i]-i)%2==0 && j%2==0) puts("Second");
            else puts("First");
        }
    }
    return 0;
}