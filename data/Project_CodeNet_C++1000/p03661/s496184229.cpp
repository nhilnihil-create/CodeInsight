#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll sum[maxn];
ll a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%lld",&a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    ll ans = INF;
    for(int i=1; i<=n-1; i++)
    {
        ll res = abs(sum[i] - (sum[n]-sum[i]));
        ans = min(ans,res);
    }
    printf("%lld",ans);
}
