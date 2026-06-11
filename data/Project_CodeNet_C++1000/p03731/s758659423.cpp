#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Welcome to my source code!

int main() {
    ll n, time;
    cin >> n >> time;
    ll t, cur = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t < cur) ans += time - (cur - t);
        else ans += time;
        cur = t + time;
    }
    cout << ans << endl;
}