#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL solve(LL a, LL b) {
    if (a == b || a == 0) return 0;
    if (a * 2 <= b) 
        return b + solve(b - a - a, b - a);
    LL d = b - a;
    return a / d * 2 * d + solve(a - a / d * d, b - a / d * d);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    LL n, x; cin >> n >> x;
    cout << x + solve(x, n) << '\n';
}
