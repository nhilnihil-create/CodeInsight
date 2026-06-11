#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 1LL << 60;
const ll mod = 1e9 + 7;

int main() {
    ll N, x;
    cin >> N >> x;
    ll a[N];
    for(int i = 0; i < N; i++) cin >> a[i];
    ll ans = 0;
    for(int i = 0; i < N; i++)
        if(a[i] > x) {
            ans += a[i] - x;
            a[i] = x;
        }
    for(int i = 1; i < N; i++) {
        ll tmp = a[i - 1] + a[i];
        if(tmp > x) {
            ans += tmp - x;
            a[i] -= tmp - x;
        }
    }
    cout << ans << "\n";
    return 0;
}