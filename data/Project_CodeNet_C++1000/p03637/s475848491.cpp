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
// 69 12 19

int gcd(int a, int b) {
    while (b != 0) {
        auto na = a % b;
        a = b;
        b = na;
    }
    return a;
}


void oneCase() {
    int n;
    cin >> n;
    int f = 0, o = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        f += (a % 4) == 0;
        o += a % 2;
    }
    if (f >= o || (f + o == n && o == f + 1)) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }



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
