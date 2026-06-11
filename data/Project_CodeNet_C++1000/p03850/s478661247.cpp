#include <bits/stdc++.h>
#define int long long 

using namespace std;

int32_t main() {
    int n; cin >> n;
    int ans; cin >> ans;

    vector<pair<char, int>> a;
    for (int i = 1; i < n; ++i) {
        char sgn; int val; cin >> sgn >> val;
        a.emplace_back(sgn, val);
    }
    n -= 1;

    // Reduce until -
    for (int i = 0; i <= n; ++i) {
        if (i == n || a[i].first == '-') {
            a.erase(a.begin(), a.begin() + i);
            break;
        } else {
            ans += a[i].second;
        }
    }

    if (a.empty()) {
        cout << ans << endl;
        return 0;
    }
    
    n = a.size(); 
    vector<int> dp(n + 1, 0);
    vector<int> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = suff[i + 1] + a[i].second;
        if (a[i].first == '-') {
            int j = i + 1;
            int now = 0;
            while (j < n && a[j].first == '+') {
                now += a[j].second;
                ++j;
            }
            dp[i] = max(
                    dp[j] + now - a[i].second, 
                    suff[j] - now - a[i].second);
        }
    }
    cout << ans + dp[0] << endl;

    return 0;
}
