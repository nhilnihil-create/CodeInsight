
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;
ll n, a, b, t, p;
ll ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (p == 0)
            p = t;
        else {
            int d = t - p;
            ans += min(d * a, b);
            p = t;
        }
    }
    cout << ans << endl;

    return 0;
}

