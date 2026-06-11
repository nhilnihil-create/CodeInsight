#include <bits/stdc++.h>
using namespace std;
#define N 100010
int a[N], n, m, num;
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
        num += a[i] & 1;
    }
    if (num > 2) {
        printf("Impossible\n");
        return 0;
    }
    for (int i = 2; i < m; i++)
        if (a[i] & 1) swap(a[(a[1] & 1) ? m : 1], a[i]);
    for (int i = 1; i < m; i++) printf("%d ", a[i]);
    printf("%d\n", a[m]);
    if (m == 1) a[++m] = a[1], a[1] = 0;
    a[1]++;
    printf("%d\n", (--a[m]) ? m : --m);
    for (int i = 1; i < m; i++) printf("%d ", a[i]);
    printf("%d\n", a[m]);
    return 0;
}