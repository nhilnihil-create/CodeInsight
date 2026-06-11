#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(3 * n), score(n + 1);
    for (int i = 0; i < 3 * n; ++i) cin >> a[i];

    priority_queue<ll> que_l, que_r;
    for (ll i = 0, sum[4] = {0, 0, 0, 0}; i < 2 * n; ++i) {
        sum[0] += a[i]; que_l.push(-a[i]);
        sum[1] += a[3 * n - i - 1]; que_r.push(a[3 * n - i - 1]);

        if (n + 1 <= (int)que_l.size()) {
            sum[2] -= que_l.top(); que_l.pop();
            sum[3] += que_r.top(); que_r.pop();
        }
        if (n - 1 <= i) {
            score[i - n + 1] += sum[0] - sum[2];
            score[2 * n - i - 1] -= sum[1] - sum[3];
        }
    }

    cout << *max_element(score.begin(), score.end()) << endl;

    return 0;
}
