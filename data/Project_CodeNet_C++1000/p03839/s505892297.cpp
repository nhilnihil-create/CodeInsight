#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n, 0), sum1(n + 1, 0), sum2(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        sum1[i + 1] = sum1[i] + a[i];
        sum2[i + 1] = sum2[i] + max(0LL, a[i]);
    }

    ll ans = 0;
    for (int i = 0; i <= n - k; ++i) {
        ll sum = max(0LL, sum1[i + k] - sum1[i]);
        sum += sum2[i] + sum2[n] - sum2[i + k];
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}