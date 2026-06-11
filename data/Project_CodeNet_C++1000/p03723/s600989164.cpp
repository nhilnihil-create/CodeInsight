#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
    ll A, B, C;
    cin >> A >> B >> C;
    ll S = A+B+C;
    if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
        puts("0");
        return 0;
    }
    ll x[3] = {A+A+A-S, B+B+B-S, C+C+C-S};
    ll ans = LLONG_MAX;
    for (int i = 0; i < 3; i++) {
        if (x[i] == 0) continue;
        ll r = 0;
        while (x[i] % 2 == 0) {
            x[i] /= 2;
            r++;
        }
        ans = min(ans, r);
    }
    if (ans == LLONG_MAX) {
        puts("-1");
        return 0;
    }
    cout << ans << endl;
}