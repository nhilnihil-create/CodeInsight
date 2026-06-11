#include <bits/stdc++.h>

using namespace std;

const int mmax = 100 + 10;

int n, m;
int a[mmax], b[mmax];

int main()
{
    //freopen("input","r",stdin);
   // freopen("output","w",stdout);

    scanf("%d %d", &n, &m);

    int odd = 0;
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &a[i]);
        odd += (a[i] & 1);
    }

    if (odd > 2) {
        printf("Impossible\n");
        return 0;
    }

    for (int i = 2; i < m; ++i) {
        if (a[i] % 2 == 0) continue;

        if (a[1] % 2 == 0) swap(a[1], a[i]);
        else swap(a[m], a[i]);
    }

    for (int i = 1; i <= m; ++i)
        printf("%d ", a[i]);
    printf("\n");

    if (m == 1) {
        if (n == 1) printf("1\n1\n");
        else printf("%d\n%d %d\n", 2, n - 1, 1);

        return 0;
    }

    b[1] = a[1] - 1;
    for (int i = 2; i < m; ++i)
        b[i] = a[i];
    b[m] = a[m]+1;

    printf("%d\n", m - (b[1] == 0));
    for (int i = 1 + (b[1] == 0); i <= m; ++i)
        printf("%d ", b[i]);

    return 0;
}
