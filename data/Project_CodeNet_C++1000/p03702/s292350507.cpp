#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e5 + 100;
int n;
ll h[maxN];
ll a, b;
bool check(ll x) {
    ll need = 0;
    for (int i = 1; i <= n; i++) {
        if (b * x >= h[i]) continue;
        need += (h[i] - b * x + a - b - 1) / (a - b);
    }
    return need <= x;
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> a >> b;
    for (int i = 1; i <= n; i++) cin >> h[i];
    ll l = 0;
    ll r = 1e9 + 100;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
    return 0;
}
