#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(3 * n), sc(n + 1);
    for (int i = 0; i < 3 * n; ++i) cin >> a[i];

    priority_queue<ll> pq_l, pq_r;
    for (ll i = 0, sum[4] = {0, 0, 0, 0}; i < 2 * n; ++i) {
        sum[0] += a[i]; pq_l.push(-a[i]);
        sum[1] += a[3 * n - i - 1]; pq_r.push(a[3 * n - i - 1]);

        if (n <= i) {
            sum[2] -= pq_l.top(); pq_l.pop();
            sum[3] += pq_r.top(); pq_r.pop();
        }
        if (n - 1 <= i) {
            sc[i - n + 1] += sum[0] - sum[2];
            sc[2 * n - i - 1] -= sum[1] - sum[3];
        }
    }

    cout << *max_element(sc.begin(), sc.end()) << endl;

    return 0;
}
