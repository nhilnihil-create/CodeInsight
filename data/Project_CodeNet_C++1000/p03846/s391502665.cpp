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

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int n;
    ll ans = 1;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    sort(a.begin(), a.end());
    if (n % 2 == 1) {
        if (a.at(0) != 0) goto last;
        for (int i = 2; i < n; i += 2) {
            if (a.at(i - 1) != i) goto last;
            if (a.at(i) != i) goto last;
        }
        rep(i, n / 2) {
            ans *= 2;
            if (ans > 1000000007) ans %= 1000000007;
        }
        cout << ans << endl;
    }
    else {
        for (int i = 1; i < n; i += 2) {
            if (a.at(i - 1) != i) goto last;
            if (a.at(i) != i) goto last;
        }
        rep(i, n / 2) {
            ans *= 2;
            if (ans > 1000000007) ans %= 1000000007;
        }
        cout << ans << endl;
    }
    return 0;
    last:
    cout << 0 << endl;
    return 0;
}