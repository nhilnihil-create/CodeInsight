#include <bits/stdc++.h>
#define SZ(x) ((int) (x).size())
using namespace std;

typedef long long i64;

int main() {
    #ifdef LOCAL_RUN
    freopen("task.in", "r", stdin);
    freopen("task.out", "w", stdout);
    //freopen("task.err", "w", stderr);
    #endif // ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n);
    vector<int64_t> sum(n + 1, 0);
    vector<int> sign(n, 1);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (i < n - 1) {
            char c;
            cin >> c;
            sign[i + 1] = c == '-' ? -1: 1;
        }
        sum[i + 1] = sum[i] + A[i];
    }

    int prev = n;

    int64_t xsum = 0;
    for (int i = 0; i < n; ++i) {
        xsum += sign[i] * A[i];
    }
    int64_t ans = xsum;
    for (int i = n - 1; i >= 0; --i) {
        if (sign[i] == -1) {
            if (prev != n) {
                int64_t csum = xsum - (sum[prev] - sum[i + 1]) + sum[n] - sum[prev];
                ans = max(ans, csum);
            }
            prev = i;
        }
        xsum -= sign[i] * A[i];
    }
    cout << ans << '\n';
}
