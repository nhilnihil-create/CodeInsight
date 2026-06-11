#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n];
    long long sum = 0, cur = 0, ans = 2e18;

    for (int i = 0; i < n; i++)
        cin >> arr[i], sum += arr[i];

    for (int i = 0; i < n - 1; i++)
        cur += arr[i], ans = min(ans, abs(cur - (sum - cur)));
    cout << ans << '\n';
}