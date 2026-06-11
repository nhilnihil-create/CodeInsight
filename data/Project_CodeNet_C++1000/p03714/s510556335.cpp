#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<ll> a(3 * n);
    rep(i, 3 * n) cin >> a[i];

    ll running_sum = 0;
    vector<ll> maxleft(3 * n, -1e18);
    priority_queue<ll, vector<ll>, greater<ll>> pqmin;
    for (int i = 0; i < 3 * n; i++) {
        pqmin.push(a[i]);
        running_sum += a[i];
        if ((int)pqmin.size() < n) continue;
        if ((int)pqmin.size() > n) {
            running_sum -= pqmin.top();
            pqmin.pop();
        }
        maxleft[i] = running_sum;
    }

    running_sum = 0;
    vector<ll> minright(3 * n, 1e18);
    priority_queue<ll> pqmax;
    for (int i = 3 * n - 1; i >= 0; i--) {
        pqmax.push(a[i]);
        running_sum += a[i];
        if ((int)pqmax.size() < n) continue;
        if ((int)pqmax.size() > n) {
            running_sum -= pqmax.top();
            pqmax.pop();
        }
        minright[i] = running_sum;
    }
    ll ans = -1e18;
    for (int i = n - 1; i < 2 * n; i++) {
        ans = max(ans, maxleft[i] - minright[i + 1]);
    }
    cout << ans << endl;
}