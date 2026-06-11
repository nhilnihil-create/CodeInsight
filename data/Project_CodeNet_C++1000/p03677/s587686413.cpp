#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<ll> b(m * 2, 0);
    vector<pair<int, ll>> c(n - 1, {0,0});
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        if (i > 0) {
            if (a[i - 1] + 1 < a[i]) {
                if (a[i - 1] + 2 < m * 2) b[a[i - 1] + 2]++;
                if (a[i] + 1 < m * 2) b[a[i] + 1]--;
                c[i - 1].first = a[i] + 1;
                c[i - 1].second = a[i] - 1 - a[i - 1];
            }
            else if (a[i] < a[i - 1] && a[i - 1] + 1 < a[i] + m) {
                if (a[i - 1] + 2 < m * 2) b[a[i - 1] + 2]++;
                if (a[i] + 1 < m) b[a[i] + m + 1]--;
                c[i - 1].first = a[i] + m + 1;
                c[i - 1].second = a[i] + m - 1 - a[i - 1];
            }
        }
    }
    for (int i = 1; i < m * 2; i++) {
        b[i] += b[i - 1];
    }
    ll sum = 0;
    for (int i = 0; i < n - 1; i++) {
        b[c[i].first] -= c[i].second;
        sum += c[i].second + 1;
    }
    for (int i = 1; i < m * 2; i++) {
        b[i] += b[i - 1];
    }
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans = max(ans, b[i] + b[i + m]);
    }
    cout << sum - ans << endl;
    return 0;
}