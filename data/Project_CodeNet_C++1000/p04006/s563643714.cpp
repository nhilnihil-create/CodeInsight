#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 2005;

int n, x;
int a[Maxn], b[Maxn];
ll res = 1000000000000000000ll;

ll Get()
{
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += a[i];
    return res;
}

int main()
{
    scanf("%d %d", &n, &x);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i <= n; i++) {
        res = min(res, Get() + ll(i) * x);
        for (int j = n; j >= 1; j--) {
            int prv = j == 1? n: j - 1;
            b[j] = min(a[j], a[prv]);
        }
        for (int j = 1; j <= n; j++)
            a[j] = b[j];
    }
    printf("%lld\n", res);
    return 0;
}
