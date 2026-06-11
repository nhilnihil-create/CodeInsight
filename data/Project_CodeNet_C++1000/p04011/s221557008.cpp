#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;

#define INF 1e9
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
    int n, k, x, y, ans = 0;
    cin >> n >> k >> x >> y;
    if (n >= k) {
        ans += k * x;
        n -= k;
    }
    else {
        ans += x * n;
        n = 0;
    }
    ans += n * y;
    cout << ans << endl;
}