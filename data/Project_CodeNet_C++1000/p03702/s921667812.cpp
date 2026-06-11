#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, A, B, h[maxn];

int main() {
    scanf("%d %d %d", &n, &A, &B), A -= B;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }
    int l = 0, r = 1e9, ans;
    auto chk = [&](int x) {
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            int r = max(0LL, h[i] - 1LL * x * B);
            sum += (r + A - 1) / A;
        }
        return sum <= x;
    };
    while (l <= r) {
        int mid = (l + r) >> 1;
        chk(mid) ? r = (ans = mid) - 1 : l = mid + 1;
    }
    printf("%d\n", ans);
    return 0;
}