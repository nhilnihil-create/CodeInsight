#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(3 * n), sc(n + 1);
    for (int i = 0; i < 3 * n; ++i) cin >> a[i];

    priority_queue<ll> pq[2];
    for (ll i = 0, sum[4] = {0, 0, 0, 0}; i < 2 * n; ++i) {
        sum[0] += a[i]; pq[0].push(-a[i]);
        sum[1] += a[3 * n - i - 1]; pq[1].push(a[3 * n - i - 1]);

        if (n <= i) {
            sum[2] -= pq[0].top(); pq[0].pop();
            sum[3] += pq[1].top(); pq[1].pop();
        }
        if (n - 1 <= i) {
            sc[i - n + 1] += sum[0] - sum[2];
            sc[2 * n - i - 1] -= sum[1] - sum[3];
        }
    }

    cout << *max_element(sc.begin(), sc.end()) << endl;

    return 0;
}
