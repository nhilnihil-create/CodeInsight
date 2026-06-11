#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(3 * n);
    for (int i = 0; i < 3 * n; ++i) cin >> a[i];

    // n <= k < 2 * n
    vector<ll> score(n + 1);

    ll sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> que1;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        que1.push(a[i]);
    }
    score[0] = sum;

    ll sum2 = 0;
    for (int i = 1; i <= n; ++i) {
        que1.push(a[n + i - 1]);
        sum += a[n + i - 1];
        sum2 += que1.top(); que1.pop();
        score[i] = sum - sum2;
    }

    sum = 0;
    priority_queue<ll> que2;
    for (int i = 0; i < n; ++i) {
        sum += a[3 * n - i - 1];
        que2.push(a[3 * n - i - 1]);
    }
    score[n] -= sum;

    ll sum3 = 0;
    for (int i = n - 1; 0 <= i; --i) {
        que2.push(a[n + i]);
        sum += a[n + i];
        sum3 += que2.top(); que2.pop();
        score[i] -= sum - sum3;
    }

    cout << *max_element(score.begin(), score.end()) << endl;

    return 0;
}
