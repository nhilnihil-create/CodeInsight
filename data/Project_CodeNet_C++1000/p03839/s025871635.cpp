#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, k;
int a[Maxn];
ll sum[Maxn];
ll L[Maxn], R[Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    L[0] = 0;
    for (int i = 1; i <= n; i++)
        L[i] = L[i - 1] + (a[i] > 0? a[i]: 0ll);
    R[n + 1] = 0;
    for (int i = n; i > 0; i--)
        R[i] = R[i + 1] + (a[i] > 0? a[i]: 0ll);
    for (int i = 1; i + k <= n + 1; i++)
        res = max(res, max(0ll, sum[i + k - 1] - sum[i - 1]) + R[i + k] + L[i - 1]);
    printf("%lld\n", res);
    return 0;
}
