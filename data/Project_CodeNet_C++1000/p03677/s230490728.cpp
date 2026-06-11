
# include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e5;
LL a[maxn+3]={0}, b[maxn+3]={0}, c[maxn+3]={0};
int main()
{
    LL sum = 0;
    int n, m;
    scanf("%d%d%lld",&n,&m,&a[1]);
    for(int i=2; i<=n; ++i)
    {
        scanf("%lld",&a[i]);
        if(a[i] > a[i-1])
        {
            sum += a[i]-a[i-1];
            b[a[i-1]+1] += a[i-1]+1;
            b[a[i]+1] -= a[i-1]+1;
            ++c[a[i-1]+1];
            --c[a[i]+1];
        }
        else
        {
            sum += m-a[i-1]+a[i];
            b[a[i-1]+1] += a[i-1]+1;
            ++c[a[i-1]+1];
            b[1] -= m-a[i-1]-1;
            ++c[1];
            b[a[i]+1] += m-a[i-1]-1;
            --c[a[i]+1];
        }
    }
    for(int i=1; i<=m; ++i)
        b[i] += b[i-1], c[i] += c[i-1];
    LL ans = 0;
    for(int i=1; i<=m; ++i)
        ans = max(ans,i*1LL*c[i]-b[i]);
    printf("%lld\n",sum-ans);
    return 0;
}