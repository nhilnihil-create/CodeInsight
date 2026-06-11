#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    if (c < a) {
        if (d <= b) cout << max((ll)0, d-a) << endl;
        else cout << b-a << endl;
    } else if (c <= b) {
        if (d <= b) cout << d-c << endl;
        else cout << b-c << endl;
    } else cout << 0 << endl;
}