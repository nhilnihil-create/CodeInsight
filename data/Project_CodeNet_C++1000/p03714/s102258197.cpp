#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    int n;
    cin >> n;
    int a[300010];
    for (int i = 0; i < n * 3; i++) {
        cin >> a[i];
    }

    ll left_sum = 0;
    priority_queue<ll, vector<ll>, greater<ll> > left_pq;
    for (int i = 0; i < n; i++) {
        left_sum += a[i];
        left_pq.push(a[i]);
    }
    ll right_sum = 0;
    priority_queue<ll> right_pq;
    for (int i = 2 * n; i < n * 3; i++) {
        right_sum += a[i];
        right_pq.push(a[i]);
    }

    ll left_p_sums[n + 1];
    left_p_sums[0] = left_sum;
    for (int i = 0; i < n; i++) {
        left_pq.push(a[i + n]);
        left_sum += a[i + n];
        left_sum -= left_pq.top();
        left_pq.pop();
        left_p_sums[i + 1] = left_sum;
    }
    ll right_p_sums[n + 1];
    right_p_sums[n] = right_sum;
    for (int i = 0; i < n; i++) {
        right_pq.push(a[2 * n - 1 - i]);
        right_sum += a[2 * n - 1 - i];
        right_sum -= right_pq.top();
        right_pq.pop();
        right_p_sums[n - 1 - i] = right_sum;
    }

    ll ans = left_p_sums[0] - right_p_sums[0];
    for (int i = 1; i <= n; i++) {
        ans = max(ans, left_p_sums[i] - right_p_sums[i]);
    }
    cout << ans << endl;
    return 0;
}
