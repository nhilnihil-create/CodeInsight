#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    ll x, y;
    ll a, b;
    ll ans = 1e9 + 7;
    cin >> x >> y;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a = pow(-1, i) * x;
            b = pow(-1, j) * y;
            if (a <= b) {
                ans = min(ans, i+j+b-a);
            }
        }
    }
    cout << ans << endl;
}