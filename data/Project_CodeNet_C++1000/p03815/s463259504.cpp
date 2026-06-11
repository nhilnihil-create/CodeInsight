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
    ll x;
    cin >> x;
    ll ans = (x / 11) * 2;
    x %= 11;
    if (x > 6) ans += 2;
    else if (x == 0);
    else ans ++;
    cout << ans << endl;
}