#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans = 0;
    rep(i, 101) {
        if (i >= a && i < b && i >= c && i < d) ans++;
    }

    cout << ans << endl;
    return 0;
}
