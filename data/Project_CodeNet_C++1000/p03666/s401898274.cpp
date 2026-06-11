#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    ll a, b, c, d; cin >> a >> b >> c >> d;
    b -= a;
    for (int i = 0; i < n; i++) {
        if (c*(n - 1 - i) - d * i <= b && b <= -c * i + d * (n - 1 - i)) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}