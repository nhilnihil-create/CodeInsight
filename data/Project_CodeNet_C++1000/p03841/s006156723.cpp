#include <bits/stdc++.h>
using namespace std;

const int maxn = 510;
int n, num[maxn], cur[maxn], pos[maxn], ans[maxn * maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]), pos[i] = i;
    }
    sort(pos + 1, pos + n + 1, [&](int x, int y) { return num[x] < num[y]; });
    for (int i = 1; i <= n * n; i++) {
        bool flag = 1;
        for (int k = 1; k <= n; k++) {
            int j = pos[k];
            if (num[j] < i) continue;
            if (num[j] == i) {
                if (cur[j] ^ (j - 1)) flag = 0;
                else ans[i] = j, cur[j]++;
                break;
            }
            if (cur[j] < j - 1) { ans[i] = j, cur[j]++; break; }
        }
        if (!flag) printf("No\n"), exit(0);
        if (!ans[i]) {
            for (int j = 1; j <= n; j++) if (num[j] < i) {
                if (cur[j] < n) { ans[i] = j, cur[j]++; break; }
            }
        }
        if (!ans[i]) {
            for (int j = 1; j <= n; j++) {
                if (cur[j] < n) { ans[i] = j, cur[j]++; break; }
            }
        }
        if (!ans[i]) printf("No\n"), exit(0);
    }
    printf("Yes\n");
    for (int i = 1; i <= n * n; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}