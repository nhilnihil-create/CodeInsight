#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long all = a*b*c;
    if (all % 2LL == 0) cout << 0 << endl;
    else {
        long long ans = min({a*b, b*c, c*a});
        cout << ans << endl;
    }
}