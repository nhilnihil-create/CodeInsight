#include <bits/stdc++.h>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
ll n, a[N], pre[N], ans;

int main() {
    cin >> n;
    rep(i, 1, n) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    rep(i, 1, n) {
        a[i] += a[i - 1];
        ans++;
        if (a[i] * 2 < a[i + 1]) ans = 0;
    }
    printf("%lld\n", ans);
    return 0;
}
