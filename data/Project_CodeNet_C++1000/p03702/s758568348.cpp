#include<bits/stdc++.h>
using namespace std;
const long long llINF = 9223372036854775807;
const int INF = 2147483647;
const int maxn = 1e5 + 7;
const int maxm = 1e6 + 7;
const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const double eps = 1e-10;

long long n, a, b;

long long h[maxn];
long long ans = llINF;
bool check(long long x)
{
    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        long long tmp = h[i] - b * x; //余震
        if (tmp <= 0) //余震震死
            continue;
        cnt += tmp / (a - b) ;
        if (tmp % (a - b))
            cnt++;
    }
    if (cnt <= x)
        ans = min(ans, x);
    return cnt <= x;
}
int main(int argc, char const *argv[])
{
    scanf("%lld%lld%lld", &n, &a, &b);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &h[i]);

    long long l = 0, r = 1e9;
    while (l <= r)
    {
        long long mid = (l + r) >> 1;
        if (check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    printf("%lld\n", ans);

    return 0;
}