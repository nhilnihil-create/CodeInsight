#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> csum_a(n + 1,0), csum_b(n + 1,0);
    for (int i = 1; i <= n; ++i) {
        long long tmp;
        cin >> tmp;
        csum_a[i] = csum_a[i - 1] + tmp;
        csum_b[i] = csum_b[i - 1] + max(tmp, 0LL);
    }

    long long ans = INT64_MIN;
    for (int i = 1; i + k - 1 <= n; ++i) {
        auto left = csum_b[i - 1];
        auto center = max(csum_a[i + k - 1] - csum_a[i - 1], 0LL);
        auto right = csum_b[n] - csum_b[i + k - 1];
        ans = max(ans, left + center + right);
    }

    cout << ans << endl;
    return 0;
}
