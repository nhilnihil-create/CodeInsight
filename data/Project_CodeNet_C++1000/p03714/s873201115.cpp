#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(3 * n);
    for (int i = 0; i < 3 * n; ++i) cin >> a[i];

    vector<ll> score(n + 1);
    ll sum_l = 0, sum_r = 0;
    priority_queue<ll, vector<ll>, greater<ll>> que_l;
    priority_queue<ll> que_r;
    for (int i = 0; i < n; ++i) {
        sum_l += a[i];
        que_l.push(a[i]);
        sum_r += a[3 * n - i - 1];
        que_r.push(a[3 * n - i - 1]);
    }
    score[0] = sum_l;
    score[n] -= sum_r;

    for (ll i = 1, sum2 = 0; i <= n; ++i) {
        que_l.push(a[n + i - 1]);
        sum_l += a[n + i - 1];
        sum2 += que_l.top(); que_l.pop();
        score[i] += sum_l - sum2;
    }
    for (ll i = n - 1, sum2 = 0; 0 <= i; --i) {
        que_r.push(a[n + i]);
        sum_r += a[n + i];
        sum2 += que_r.top(); que_r.pop();
        score[i] -= sum_r - sum2;
    }

    cout << *max_element(score.begin(), score.end()) << endl;

    return 0;
}
