#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;


int main() {
    ll n, m;
    cin >> n >> m;
    ll ans = 1;
    if (abs(n - m) > 1) {
        cout << 0 << endl;
        return 0;
    }
    rep(i, n) {
        ans *= (i + 1);
        if (ans > 1000000007) {
            ans %= 1000000007;
        }
    }
    rep(i, m) {
        ans *= (i + 1);
        if (ans > 1000000007) {
            ans %= 1000000007;
        }
    }
    if (abs(n - m) % 2 == 0) {
        ans *= 2;
    }
    if (ans > 1000000007) {
        ans %= 1000000007;
    }
    cout << ans << endl;
}