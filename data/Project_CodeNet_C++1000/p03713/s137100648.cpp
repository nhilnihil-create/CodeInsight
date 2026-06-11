#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;

ll ans = 10000000005;

void setans(ll a, ll b, ll c) {
// cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
    if (a == 0 || b == 0 || c == 0) {
        return;
    }
    ll x = max(a, max(b, c));
    ll y = min(a, min(b, c));
    ans = min(ans, x - y);
}

void f(ll x, ll y) {
    for (int i = 1; i < x; i++) {
        // 面積
        ll a = i * y;
        ll b = (x - i) / 2 * y;
        ll c = (x - i - (x - i) / 2) * y;
        setans(a, b, c);

        b = (x - i) * (y / 2);
        c = (x - i) * (y - y / 2);
        setans(a, b, c);
    }
}

int main() {
    int H, W;
    cin >> H >> W;
    
    f(H, W);
    f(W, H);
    cout << ans << endl;
}