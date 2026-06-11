#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 5e3 + 7;
const int INF = 1e9 + 7;
const double pi = acos(-1.0);
const int MOD = 1e9 + 7;

int main() {
    long long ans = 1;
    int n, x;
    scanf("%d", &n);
    int cnt = 0, out = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x < (i - out) * 2 + 1) {
            ans *= cnt + 1;
            ans %= MOD;
            out++;
        } else cnt++;
    }
    for (int i = 2; i <= cnt; i++) {
        ans *= i;
        ans %= MOD;
    }
    printf("%d\n", (int)ans);
}
