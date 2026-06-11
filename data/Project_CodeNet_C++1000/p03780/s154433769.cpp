#include <bits/stdc++.h>
using namespace std;
#define N 5010
bitset<N> dp; int num[N];
int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1;i <= n;i++) scanf("%d", &num[i]);
    sort(num + 1, num + n + 1, [=](int i, int j){return i > j;});
    dp[0] = 1; int ans = 0;
    for (int i = 1;i <= n;i++) {
        int flag = 0;
        for (int j = k - 1;j >= max(0, k - num[i]);j--) 
            if (dp[j]) {flag = 1; ans = 0; break;}
        if (num[i] < k) dp |= dp << num[i];
        if (!flag) ans++;
    }
    printf("%d\n", ans);
    return 0;
}