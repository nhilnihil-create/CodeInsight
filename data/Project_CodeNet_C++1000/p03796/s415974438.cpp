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
    ll n, ans = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans *= i;
        if (ans > 1000000007) {
            ans %= 1000000007;
        }
    }
    cout << ans << endl;
}