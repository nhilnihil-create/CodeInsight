#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < ll(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    // prev[i] := minimum index where the value less than a[i] appeared before i
    // next[i] := minimum index where the value less than a[i] appeared after i
    vector<int> prev(n, 0), next(n, n);
    stack<pair<int, int>> stk;
    stk.push({0, -1});  // 番兵
    rep(i, n) {
        while (stk.size() > 0 && stk.top().first >= a[i]) stk.pop();
        prev[i] = stk.top().second + 1;
        stk.push({a[i], i});
    }

    while (!stk.empty()) stk.pop();
    stk.push({0, n});
    rep(i, n) {
        while (stk.size() > 0 && stk.top().first >= a[n - i - 1]) stk.pop();
        next[n - i - 1] = stk.top().second;
        stk.push({a[n - i - 1], n - i - 1});
    }

    ll ans = 0;
    rep(i, n) {
        ans += a[i] * (next[i] - i) * (i + 1 - prev[i]);
    }
    cout << ans << endl;
}