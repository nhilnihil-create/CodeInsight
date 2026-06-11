#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    ll n;
    cin >> n;
    ll a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll before = 1, tmp = 0, sum = a[0];

    if(a[0] < 1) {
        tmp += 1 - a[0];
        sum = 1;
    }
    for(int i = 1; i < n; i++) {
        sum += a[i];
        before *= -1;
        if(sum == 0) {
            sum = before;
            tmp++;
        }
        if(before != (sum / llabs(sum))) {
            tmp += llabs(before) + llabs(sum);
            sum = before;
        }
    }
    ll ans = tmp;

    before = -1, tmp = 0, sum = a[0];
    if(a[0] > -1) {
        tmp += 1 + a[0];
        sum = -1;
    }
    for(int i = 1; i < n; i++) {
        sum += a[i];
        before *= -1;
        if(sum == 0) {
            sum = before;
            tmp++;
        }
        if(before != (sum / llabs(sum))) {
            tmp += llabs(before) + llabs(sum);
            sum = before;
        }
    }
    ans = min(ans, tmp);
    cout << ans << "\n";

    return 0;
}
