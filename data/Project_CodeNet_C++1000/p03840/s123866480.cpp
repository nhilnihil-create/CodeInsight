#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
    ll ai, ao, at, aj, al, as, az;
    cin >> ai >> ao >> at >> aj >> al >> as >> az;
    ll ans = 0;
    ans += ai / 2 * 2;
    ans += al / 2 * 2;
    ans += aj / 2 * 2;
    ans += ao;
    if (ai && al && aj) {
        ll tmp = ai % 2 + al % 2 + aj % 2;
        if (tmp == 3) ans += 3;
        if (tmp == 2) ans += 1;
    }
    cout << ans << endl;
    return 0;
}
