#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
long long  a[maxn];
long long  b[maxn<<1];
int c[maxn<<1];
long long sum;
    int n,m;
void f(int i) {
    if(a[i]>a[i-1]) {
        sum+=a[i]-a[i-1];
        b[a[i-1]+1]+=a[i-1]+1;
        b[a[i]+1]-=a[i-1]+1;
        c[a[i-1]+1]++;
        c[a[i]+1]--;
    } else {
        sum += m-a[i-1]+a[i];
        b[a[i-1]+1] += a[i-1]+1;
        b[a[i]+1] += m-a[i-1]-1;
        b[1] -= m-a[i-1]-1;
        c[1]++;
        c[a[i-1]+1]++;
        c[a[i]+1]--;
    }
}
int main() {
//    freopen("in.txt","r",stdin);
    sum=0;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; ++i)
        scanf("%lld",&a[i]);
    for(int i=2; i<=n; ++i) {
        f(i);
    }
    for(int i=1; i<=m; ++i) {
        c[i]+=c[i-1];
        b[i]+=b[i-1];
    }
    long long  ma=0;
    for(int x=1; x<=m; ++x) {
        if(c[x]) {
            ma=max(ma,1ll*x*c[x]-b[x]);
        }
    }
    printf("%lld\n",sum-ma);
    return 0;
}
