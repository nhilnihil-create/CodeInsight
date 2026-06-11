#include <cstdio>
#define FOR(i, l, r) for(int i = l; i <= r; ++i)
using namespace std;

int n, a[310][310];
long long ans;

int main()
{
    scanf("%d", &n);
    FOR(i, 1, n) FOR(j, 1, n) scanf("%d", &a[i][j]);
    FOR(i, 1, n) FOR(j, i + 1, n)
    {
        bool fl = 1;
        FOR(k, 1, n) if (k != i && k != j)
        {
            if (a[i][k] + a[k][j] == a[i][j]) fl = 0; else
            if (a[i][k] + a[k][j] < a[i][j]) {puts("-1"); return 0;}
        }
        if (fl) ans += a[i][j];
    }
    printf("%lld\n", ans);
    return 0;
}
