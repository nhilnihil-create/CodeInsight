#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    long long arr[M], pre[M] = {}, suf[M] = {}, pref[M] = {}, suff[M] = {}, sum = 0, ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> arr[i], sum += arr[i];

    for (int i = 1; i <= n; i++)
        pre[i] = arr[i] + pre[i - 1], pref[i] = max(0ll, arr[i]) + pref[i - 1];
    for (int i = n; i >= 0; i--)
        suf[i] = arr[i] + suf[i + 1], suff[i] = max(0ll, arr[i]) + suff[i + 1];

    for (int i = k; i <= n; i++) {
        long long left, mid, right;
        left = pref[i - k];
        right = suff[i + 1];
        mid = sum - (pre[i - k] + suf[i + 1]);
        ans = max(ans, left + right + max(mid, 0ll));
    }
    cout << ans << "\n";

    return 0;
}