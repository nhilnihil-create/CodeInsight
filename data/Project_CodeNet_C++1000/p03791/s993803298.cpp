#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll mod = 1e9 + 7;
ll ans = 1;
ll pos[100010];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> pos[i];
    ll cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt++;
        if (pos[i] >= cnt * 2 - 1) continue;
        ans *= cnt--;
        ans %= mod;
    }
    while (cnt > 0) {
        ans *= cnt--;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
