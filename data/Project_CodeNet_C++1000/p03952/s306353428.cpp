#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n, x;
    cin >> n >> x;
    int k = 2 * n - 1;
    int m = k / 2;
    if (x == 1 || x == k) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    if (n == 2) {
        for (int i = 0; i < k; i++) {
            cout << i + 1 << endl;
        }
        return 0;
    }
    bool use[k + 1] = {};
    int ans[k];
    if (x == k - 1) {
        ans[m - 2] = x - 2;
        ans[m - 1] = x + 1;
        ans[m] = x;
        ans[m + 1] = x - 1;
        use[x - 2] = true;
        use[x + 1] = true;
        use[x] = true;
        use[x - 1] = true;
    } else {
        ans[m - 2] = x + 2;
        ans[m - 1] = x - 1;
        ans[m] = x;
        ans[m + 1] = x + 1;
        use[x + 2] = true;
        use[x - 1] = true;
        use[x] = true;
        use[x + 1] = true;
    }
    int cur = 1;
    for (int i = 0; i < m - 2; i++) {
        while (use[cur]) cur++;
        ans[i] = cur;
        use[cur] = true;
    }
    for (int i = m + 2; i < k; i++) {
        while (use[cur]) cur++;
        ans[i] = cur;
        use[cur] = true;
    }
    for (int i = 0; i < k; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}