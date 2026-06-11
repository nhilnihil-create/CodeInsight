#include <cstdio>
#include <algorithm>
#define FOR(i, l, r) for(int i = l; i <= r; ++i)
using namespace std;

int n, m, tot;
int a[110];

int main()
{
    scanf("%d%d", &n, &m);
    FOR(i, 1, m)
    {
        scanf("%d", &a[i]);
        if (a[i] & 1) ++tot;
    }
    if (tot > 2) {puts("Impossible"); return 0;}

    if (m == 1)
    {
        if (n == 1) printf("1\n1\n1\n"); else
            printf("%d\n2\n1 %d\n", n, n - 1);
        return 0;
    }

    FOR(i, 1, m) if (a[i] & 1) {swap(a[i], a[1]); break;}
    FOR(i, 2, m) if (a[i] & 1) {swap(a[i], a[m]); break;}

    FOR(i, 1, m) printf("%d ", a[i]); puts("");
    if (a[1] == 1) printf("%d\n", m - 1); else printf("%d\n%d ", m, a[1] - 1);
    FOR(i, 2, m - 1) printf("%d ", a[i]);
    printf("%d\n", a[m] + 1);

    return 0;
}
