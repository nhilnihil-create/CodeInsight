#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define l first
#define r second

using namespace std;

const int maxn = 3e5 + 1;

int a[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x = max(x, a[i]);
        y = __gcd(y, a[i]);
    }
    if (k <= x && k % y == 0) {
        cout << "POSSIBLE";
    } else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}
