#include <bits/stdc++.h>
using namespace std;
const int N = 100020;
int n,q,f[N][30]; long long x[N],L;
int main(void)
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&x[i]);
    scanf("%lld\n%d",&L,&q);
    for (int i=1;i<=n;i++)
        f[i][0] = upper_bound( x+1 , x+n+1 , x[i] + L ) - x - 1;
    for (int k=1;k<=25;k++)
        for (int i=1;i<=n;i++)
            f[i][k] = f[f[i][k-1]][k-1];
    for (int i=1;i<=q;i++)
    {
        int a , b , ans = 0;
        scanf("%d%d",&a,&b);
        if ( a > b ) swap( a , b );
        for (int k=25;k>=0;k--)
            if ( f[a][k] < b ) a = f[a][k] , ans += 1<<k;
        if ( a < b ) a = f[a][0] , ans += 1;
        printf("%d\n",ans);
    }
    return 0;
}
