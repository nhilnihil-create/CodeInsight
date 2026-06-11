#include <bits/stdc++.h>

using namespace std;
const int N = 2e3 + 10;
int a[N], mn[N][N];

int main()
{
  	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, x; cin >> n >> x;
    long long ans = 0;
    for (int i = 0; i < n; i++) cin >> a[i], mn[i][0] = a[i], ans += a[i];
    for (int t = 1; t < n; t++) {
        long long res = 1ll * t * x;
        for (int i = 0; i < n; i++) mn[i][t] = min(mn[(i - 1 + n) % n][t - 1], a[i]), res += mn[i][t];
        ans = min(ans, res);
    }
    cout << ans << "\n";

    return 0;
}
