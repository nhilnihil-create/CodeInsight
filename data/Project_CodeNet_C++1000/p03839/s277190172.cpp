/* 
    B - Contiguous Repainting
*/ 
#include <bits/stdc++.h>
#define md(x, y)  (x + y) / 2
#define ls(x)      x << 1
#define rs(x)      x << 1 | 1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 10;
ll n, a[MAXN], k, pre[MAXN], sum[MAXN];
int main()
{
    cin >> n >> k;
    ll cur = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
        if(i <= k)
            cur += a[i];
        if(a[i] > 0)
            sum[i] = sum[i - 1] + a[i];
        else 
            sum[i] = sum[i - 1];
    }
    //cur是[1, k] 区间的和.
    //     [i, k + i - 1]
    ll ans = -INF;
    for(int i = 1; i + k - 1<= n; i++)
    {
        if(i > 1)
            cur += -a[i - 1] + a[i + k - 1];
        //printf("cur = %d\n", cur);
        ll ret = sum[n] - sum[k + i - 1] + sum[i - 1];
        //printf("Ret = %d\n", ret);
        ans = max(max(ret + cur, ret + 0), ans);
    }
    printf("%lld\n", ans);

    return 0;
}