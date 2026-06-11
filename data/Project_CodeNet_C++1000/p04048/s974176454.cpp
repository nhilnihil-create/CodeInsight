#include <bits/stdc++.h>
using namespace std;
typedef int64_t Int;
#define dump(x) cout << (x) << '\n'
Int mod = 1e9+7;

Int gcd(Int n, Int m) {
    Int a = max(n, m);
    Int b = min(n, m);
    return a % b == 0 ? b : gcd(b, a % b);
}

int main() {
    Int n, x;
    cin >> n >> x;
    if (n % x == 0) {
        dump((n - x) * 3LL);
        return 0;
    }
    Int res = x;
    Int tmp = n - x;
    n = x;
    x = tmp;
    if (n % x == 0) {
        dump(res + 2LL * (n / x));
        return 0;
    }
    // cout << n << " " << x << endl;
    res += x + (n / x) * (2LL * x);
    while (true) {
        tmp = n % x;
        n = x;
        x = tmp;
        // cout << n << " " << x << endl;
        if (n % x == 0) {
            res += (n / x) * (2LL * x) - x;
            break;
        }
        else {
            res += (n / x) * (2LL * x);
        }
    } 
    dump(res);
    return 0;
}