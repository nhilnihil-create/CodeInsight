#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    function<bool(bool)> solve = [&](bool player) {
        int cnt = 0, g = 0;
        for (int i = 1; i <= n; i++) {
            if (!(a[i] & 1)) cnt++;
            g = __gcd(g, a[i] - (a[i] & 1));
        }
        if (cnt & 1) return player;
        if (n - cnt > 1 || *min_element(a + 1, a + n + 1) == 1) return !player;
        for (int i = 1; i <= n; i++) a[i] /= g;
        return solve(!player);
    };
    printf("%s\n", solve(1) ? "First" : "Second");
    return 0;
}