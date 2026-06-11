#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn], st[20][maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), st[0][i] = i;
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            int x = a[st[i - 1][j]], y = a[st[i - 1][j + (1 << (i - 1))]];
            st[i][j] = x < y ? st[i - 1][j] : st[i - 1][j + (1 << (i - 1))];
        }
    }
    auto query = [&](int l, int r) {
        int k = log2(r - l + 1);
        int x = a[st[k][l]], y = a[st[k][r - (1 << k) + 1]];
        return x < y ? st[k][l] : st[k][r - (1 << k) + 1];
    };
    function<long long(int, int)> solve = [&](int l, int r) {
        if (l > r) return 0LL;
        int t = query(l, r);
        return solve(l, t - 1) + solve(t + 1, r) + 1LL * a[t] * (t - l + 1) * (r - t + 1);
    };
    printf("%lld\n", solve(1, n));
    return 0;
}