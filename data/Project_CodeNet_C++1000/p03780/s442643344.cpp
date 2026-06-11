#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

ll n, k;
ll a[5005];
ll dp[5005][5005];
ll ans = 0;

int main() {

    cin >> n >> k;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    ll valid = 0, invalid = n + 1;

    while (invalid - valid > 1) {

        ll mid = (invalid + valid) / 2;
    
        for (ll i = 0; i <= n; i++) {
            for (ll j = 0; j <= k; j++) {
                dp[i][j] = 0;
            }
        }
        
        dp[0][0] = 1;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 0; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (j >= a[i] && i != mid) {
                    dp[i][j] += dp[i - 1][j - a[i]];
                }
            }
        }

        bool f = a[mid] < k;
        for (ll i = max(0ll, k - a[mid]); f && i < k; i++) {
            if (dp[n][i]) f = false;
        }

        if (f) {
            valid = mid;
        }
        else {
            invalid = mid;
        }
    }

    cout << valid << endl;

    return 0;
}
