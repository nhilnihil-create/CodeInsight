#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    vector<vector<bool>> b(n + 2, vector<bool>(k + 1)), c(n + 2, vector<bool>(k + 1));
    b[0][0] = true;
    c[n + 1][0] = true;

    rep(i, 0, n) {
        b[i + 1] = b[i];
        rep(j, 0, k) if (b[i][j]) {
            if (k > j + a[i])
                b[i + 1][j + a[i]] = true;
            else
                break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        c[i + 1] = c[i + 2];
        rep(j, 0, k) if (c[i + 2][j]) {
            if (k > j + a[i])
                c[i + 1][j + a[i]] = true;
            else
                break;
        }
    }
    int ans = n;
    rep(i, 0, n) {
        if (a[i] >= k) {
            ans--;
            continue;
        }
        int sum = 0;
        vector<int> x;
        x.emplace_back(-1e5);
        rep(j, 0, k) if (c[i + 2][j]) x.emplace_back(j);
        x.emplace_back(k);
        rep(j, 0, k) if (b[i][j]) {
            int s = j;
            int t = *(lower_bound(x.begin(), x.end(), k - s) - 1);
            if (0 <= s + t && s + t < k)
                sum = max(s + t, sum);
            if (sum + a[i] >= k) {
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}