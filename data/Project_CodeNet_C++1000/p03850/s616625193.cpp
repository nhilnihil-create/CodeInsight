//
// Created by Administrator on 2020/2/6.
//

#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 10;
long long a[maxn], pre[maxn], sum[maxn];
char opt[maxn];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 1; i < n; ++i) {
            scanf("%lld %c", &a[i], &opt[i]);
            pre[i] = pre[i - 1] + a[i];
            if (i > 1 && opt[i - 1] == '-') sum[i] = sum[i - 1] - a[i];
            else sum[i] = sum[i - 1] + a[i];
        }
        scanf(" %lld", &a[n]);
        if (opt[n - 1] == '-') sum[n] = sum[n - 1] - a[n];
        else sum[n] = sum[n - 1] + a[n];
        pre[n] = pre[n - 1] + a[n];
        long long ans = sum[n];
        for (int i = 1; i < n; ++i) {
            if (opt[i] == '-') {
                long long temp = 0;
                int j;
                for (j = i + 1; j < n; ++j)
                    if (opt[j] == '-') break;
                temp = sum[i] - (pre[j] - pre[i]) + pre[n] - pre[j];
//                printf("%lld %d %d %lld %lld %lld\n", temp, i, j, sum[i], pre[j], pre[n]);
                ans = max(ans, temp);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}

