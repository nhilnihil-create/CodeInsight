#include <bits/stdc++.h>
#define maxN 52

using namespace std;

//FILE *fin = freopen("b.in", "r", stdin);

/* ----------------------------------------- */
long long k;
/* ----------------------------------------- */
long long a[maxN];

int main()
{
    scanf("%lld", &k);
   int n = 50;
    for (int i = 1; i <= n; ++ i)
        a[i] = (k / n) + i - 1;
    for (int i = 1; i <= k % n; ++ i)
    {
        for (int j = 1; j <= n; ++ j)
            -- a[j];
        a[i] += n + 1;
    }
    printf("%d\n", n);
    for (int i = 1; i <= n; ++ i)
        printf("%lld ", a[i]);
    return 0;
}
