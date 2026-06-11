#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, C, K, a[maxn];

int main() {
    scanf("%d %d %d", &n, &C, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int cur = 1, i, ans = 0;
    while (cur <= n) {
        for (i = cur; i <= min(cur + C - 1, n); i++) {
            if (a[i] > a[cur] + K) break;
        }
        cur = i, ans++;
    }
    printf("%d\n", ans);
    return 0;
}