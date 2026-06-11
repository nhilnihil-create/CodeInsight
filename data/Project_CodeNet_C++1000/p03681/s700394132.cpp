#include <iostream>
using namespace std;
#define rep(i, n) for(int i=n; i>1; --i)
const int mod = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    long long ans = 1;
    if (abs(n-m) > 1) ans = 0;
    if (n == m) ans *= 2;
    rep(i, n) {
        ans *= i;
        ans %= mod;
    }
    rep(i, m) {
        ans *= i;
        ans %= mod;
    }
    cout << ans << endl;
}