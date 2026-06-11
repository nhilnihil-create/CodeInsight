#include <cassert>
#include <numeric>
#include <iostream>
using namespace std;

long long check(int n, int *a, bool *neg) {
    long long maxval[n+1][n+1], minval[n+1][n+1];
    for (int i = 0; i < n; i++)
        maxval[i][i+1] = minval[i][i+1] = a[i];
    for (int w = 2; w <= n; w++)
        for (int i = 0, j = w; j <= n; i++, j++) {
            long long mx = -(1LL<<60), mn = 1LL<<60;
            for (int k = i + 1; k < j; k++) {
                // [i, k), [k, j)
                if (neg[k]) {
                    mx = max(mx, maxval[i][k] - minval[k][j]);
                    mn = min(mn, minval[i][k] - maxval[k][j]);
                } else {
                    mx = max(mx, maxval[i][k] + maxval[k][j]);
                    mn = min(mn, minval[i][k] + minval[k][j]);
                }
            }
            maxval[i][j] = mx;
            minval[i][j] = mn;
        }
    return maxval[0][n];
}

int main() {
    int n; cin >> n;
    int a[n];
    bool neg[n];
    cin >> a[0];
    neg[0] = false;
    for (int i = 1; i < n; i++) {
        char c; cin >> c >> a[i];
        neg[i] = c == '-';
    }
    long long pref[n+1], suf[n+1];
    pref[0] = 0; suf[n] = 0;
    for (int i = 0; i < n; i++)
        pref[i+1] = pref[i] + a[i] * (neg[i] ? -1 : 1);
    for (int i = n-1; i >= 0; i--)
        suf[i] = suf[i+1] + a[i];
    // for (int i = 0; i <= n; i++) cerr << pref[i] << ' '; cerr << endl;
    // for (int i = 0; i <= n; i++) cerr << suf[i] << ' '; cerr << endl;
    long long ans = pref[n];
    for (int i = n-1, j = n; i >= 0; i--) {
        if (neg[i]) {
            ans = max(ans, pref[i] - suf[i] + 2 * suf[j]);
            j = i;
        }
    }
    cout << ans << endl;
    // if (ans != check(n, a, neg)) {
    //     cerr << "WA\n";
    //     cerr << n << endl;
    //     for (int i = 0; i < n-1; i++) cerr << a[i] << ' ' << (neg[i+1] ? '-' : '+') << ' ';
    //     cerr << ' ' << a[n-1] << endl;
    // }
}
