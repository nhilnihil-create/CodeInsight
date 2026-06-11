#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn], c[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), c[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    if (a[n - 1] ^ a[n]) {
        printf("Impossible\n"), exit(0);
    }
    c[a[n]] -= 2;
    for (int i = 1; i < a[n]; i++) {
        int d = max(i, a[n] - i);
        if (!c[d]--) printf("Impossible\n"), exit(0);
    }
    for (int i = 1; i <= (a[n] + 1) / 2; i++) {
        if (c[i]) printf("Impossible\n"), exit(0);
    }
    printf("Possible\n");
    return 0;
}