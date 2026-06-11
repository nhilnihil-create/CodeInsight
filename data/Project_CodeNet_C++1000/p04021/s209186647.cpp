#include <bits/stdc++.h>
using namespace std;
#define N 100010
int a[N], b[N], n, k;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        if ((lower_bound(b + 1, b + n + 1, a[i]) - b - i) & 1) k++;
    printf("%d\n", (k >> 1));
    return 0;
}