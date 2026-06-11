#include <iostream>
using namespace std;
const int N=20000+10;
int n,p[N],a[N],b[N];
int main() {
    scanf("%d",&n);
    a[1]=5e8,b[1]=5e8;
    for(int i=2;i<=n;i++) {
        a[i]=a[i-1] + (n+1);
        b[i]=b[i-1] - (n+1);
    }
    for(int i=1;i<=n;i++) {
        scanf("%d",&p[i]);
        b[p[i]]+=i;
    }
    for(int i=1;i<=n;i++) printf("%d%c", a[i],i==n?'\n':' ');
    for(int i=1;i<=n;i++) printf("%d%c", b[i],i==n?'\n':' ');
}