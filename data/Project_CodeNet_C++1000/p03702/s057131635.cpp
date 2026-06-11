#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

ll n, a, b, h[100000];

bool p(ll c) {
    ll r = 0;
    for (ll i = 0; i < n; i++) {
        ll t = h[i] - b * c;
        if (t > 0) {
            if (t % (a - b)) r += t / (a - b) + 1;
            else r += t / (a - b);
        }
    }
    return r <= c;
}

int main() {
    cin >> n >> a >> b;
    for (ll i = 0; i < n; i++) cin >> h[i];
    ll l = 0,r = 2000000000;
    while(r - l > 1) {
        int m = (l + r) / 2;
        if(p(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
}