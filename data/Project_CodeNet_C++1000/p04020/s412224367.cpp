#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;

    ll ans = 0, sum = 0;
    rep(i, n) {
        int a;
        cin >> a;
        sum += a;

        if (a == 0) {
            ans += sum / 2;
            sum = 0;
        }
    }

    ans += sum / 2;

    cout << ans << endl;

    return 0;
}