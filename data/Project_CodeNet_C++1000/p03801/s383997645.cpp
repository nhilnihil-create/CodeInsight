#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N=1e5+10;
int a[N],p[N];
ll sum[N],ans[N];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        p[i]=i;
    }
    sort(p+1,p+n+1,[&](const int &i,const int &j){ return a[i]>a[j] || a[i]==a[j] && i<j; });
    ll now=0;
    int pos=1;
    int i=p[pos];
    ll sum=0;
    while (i) {
        while (pos<=n && p[pos]>=i) {
            sum+=a[p[pos]];
            ++pos;
        }
        ll tmp=1LL*(pos-1)*a[p[pos]];
        ans[i]+=sum-tmp;
        sum=tmp;
        i=p[pos];
    }
    for (int i=1;i<=n;i++) {
        printf("%lld\n",ans[i]);
    }
    return 0;
}