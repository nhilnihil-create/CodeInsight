#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;


// 68 11 55 - rank 3
// 69 12 19 - rank 3
// 70 12 34 - rank 100
// 71 12 58 - rank 4
// 72 13 24

ull gcd(ull a, ull b) {
    while (b != 0) {
        auto na = a % b;
        a = b;
        b = na;
    }
    return a;
}


void oneCase() {
    int x, t;
    cin >> x >> t;
    cout << max(0, x - t) << "\n";

}


int main() {
    int t = 1;
//    cin >> t;
    while (t--) {
       oneCase();
    }

    return 0;
}

ll fact(ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        res = (res * n) % mod;
        --n;
    }
    return res;
}
