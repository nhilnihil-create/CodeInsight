#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<ll> b(N + 1, 0);
    for (int i = 1; i < N + 1; i++) {
        b[i] = b[i - 1] + (a[i - 1] > 0 ? a[i - 1] : 0);
    }
    vector<ll> c(a.size() + 1, 0);
    partial_sum(a.begin(), a.end(), c.begin() + 1);

    ll ans = 0;
    for (int i = 0; i < N - K + 1; i++) {
        ll sum = (b[i] - b[0]) + (b[N] - b[i + K]);
        sum += max(0LL, c[i + K] - c[i]);
        ans = max(ans, sum);
    }
    cout << ans << endl;
}