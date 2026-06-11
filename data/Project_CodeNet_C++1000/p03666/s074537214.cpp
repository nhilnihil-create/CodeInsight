#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
 
int main() {
    int n; cin >> n;
    ll a, b, c, d; cin >> a >> b >> c >> d;
    b -= a;
    ll l = -(n-1) * d, r = -(n-1) * c;
    for (int i = 0; i < n; i++) {
        if (l <= b && b <= r) {
            puts("YES");
            return 0;
        }
        l += c + d;
        r += c + d;
    }
    puts("NO");
    return 0;
}