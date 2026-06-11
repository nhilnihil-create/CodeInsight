#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int mod = 1e9 + 7;

int n, x[N];
int cnt[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];

    int cannot = 0;
    for (int i = 1; i <= n; ++i) {
        cnt[cannot]++;
        // update cannot
        if (x[i] < 2 * (i - cannot) - 1) ++cannot;
    }

    int cur = 0;
    int res = 1;
    for (int i = 0; i < n; ++i) {
        cur += cnt[i];
        res = 1LL * res * (cur - i) % mod;
    }

    cout << res << endl;
}