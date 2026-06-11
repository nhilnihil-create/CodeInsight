#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3fLL;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> l(n + 1, 0), r(n + 1, 0);
    for (int i = 0; i < n; i++) {
        l[i + 1] = l[i] + a[i];
        r[n - i - 1] = r[n - i] + a[n - i - 1];
    }
    ll ans = linf;
    for (int i = 1; i < n; i++) {
        ans = min(ans, abs(l[i] - r[i]));
    }
    cout << ans << endl;
    return 0;
}