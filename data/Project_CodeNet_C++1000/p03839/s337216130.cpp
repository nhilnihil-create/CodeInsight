#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define pb push_back
#define dbg(x) cerr << #x << " " << x << "\n"

const int N = 1e5;
ll sum[1 + N];
ll l[1 + N + 1];
ll r[1 + N + 1];
int a[1 + N];

int main () {
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
        l[i] = l[i - 1] + max (0, a[i]);
    for (int i = n; i > 0; i--)
        r[i] = r[i + 1] + max (0, a[i]);
    ll ans = -(1ll << 60);
    for (int i = 1; i + k - 1 <= n; i++) {
        int x = i;
        int y = i + k - 1;
        ans = max (ans, sum[y] - sum[x - 1] + l[x - 1] + r[y + 1]);
        ans = max (ans, l[x - 1] + r[y + 1]);
    }
    cout << ans << "\n";
    return 0;
}
