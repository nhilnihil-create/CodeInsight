#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;
using ld = long double;
const int MOD = 1e9 + 7;

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    if(a == b && n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(n == 1 || b < a) {
        cout << 0 << endl;
        return 0;
    }

    cout << (b - a) * (n - 2) + 1 << endl;

    return 0;
}
