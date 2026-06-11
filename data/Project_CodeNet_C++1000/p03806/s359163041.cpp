#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>


using std::cout;
using std::cin;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


ll gcd(ll a, ll b) {
    while (b != 0) {
        auto tmp = a;
        a = b;
        b = tmp % a;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int isPrime(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}


void oneCase () {
    int n, ma, mb;
    cin >> n >> ma >> mb;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;

        a[i] = x;
        b[i] = y;
        c[i] = z;
    }

    auto maxWeight = n * 10;
    vector<vector<int>> dp(maxWeight + 1, vector<int>(maxWeight + 1, 1e9));

    for (int i = 0; i < n; ++i) {
        auto ndp = dp;
        auto x = a[i];
        auto y = b[i];
        for (int l = 1; l <= maxWeight - x; ++l) {
            for (int r = 1; r <= maxWeight - y; ++r) {
                ndp[x + l][y + r] = min(ndp[x + l][y + r], dp[l][r] + c[i]);
            }
        }
        ndp[x][y] = min(ndp[x][y], c[i]);
        swap(dp, ndp);
    }

    int best = 1e9;
    int x = 0;
    int y = 0;

    while (true) {
        x += ma;
        y += mb;
        if (max(x, y) > maxWeight) {
            break;
        }
        best = min(best, dp[x][y]);
    }
    if (best == 1e9) {
        best = -1;
    }
    cout << best << "\n";
}





int main() {
    int t = 1;
//    cin >> t;
    while (t > 0) {
        oneCase();
        --t;
    }

    return 0;
}