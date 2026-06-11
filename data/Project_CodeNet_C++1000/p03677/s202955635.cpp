#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, a[maxn];
long long sum, cnt[maxn], tmp[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i + 1]) {
            sum += a[i + 1] - a[i];
            cnt[a[i] + 2]--, cnt[a[i + 1] + 1]++;
            tmp[a[i + 1] + 1] += a[i + 1] - a[i] - 1;
        } else {
            sum += a[i + 1] + m - a[i];
            cnt[a[i] + 2]--;
            tmp[1] -= m - a[i] - 1, tmp[a[i + 1] + 1] += m - a[i] - 1;
            cnt[1]--, cnt[a[i + 1] + 1]++;
            tmp[a[i + 1] + 1] += a[i + 1];
        }
    }
    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }
    long long ans = 1e18;
    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1], tmp[i] += tmp[i - 1];
        ans = min(ans, sum + cnt[i] + tmp[i]);
    }
    printf("%lld\n", ans);
    return 0;
}