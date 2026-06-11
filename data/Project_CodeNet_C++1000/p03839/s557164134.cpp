#include <iostream>
#include <vector>

#define ll long long
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];

    vector<ll> sum(n + 1);
    for (int i = 0; i < n; i++)sum[i + 1] = sum[i] + a[i];

    vector<ll> left_onlyplus_sum(n + 1);
    for (int i = 0; i < n; i++)left_onlyplus_sum[i + 1] = left_onlyplus_sum[i] + max(0, a[i]);
    vector<ll> right_onlyplus_sum(n + 1);
    for (int i = n; i > 0; i--)right_onlyplus_sum[i - 1] = right_onlyplus_sum[i] + max(0, a[i - 1]);

    ll ret = 0;
    for (int i = 0; i + k <= n; i++)
        ret = max(ret, left_onlyplus_sum[i] + max(0LL, sum[i + k] - sum[i]) + right_onlyplus_sum[i + k]);

    cout << ret << endl;
    return 0;
}