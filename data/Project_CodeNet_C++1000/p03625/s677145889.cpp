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
// 71 12 58 -

ull gcd(ull a, ull b) {
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
    map<ll, int> s;
    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        ++s[-a];
    }
    ll last = 0;
    for (auto p : s) {
        if (p.second == 1) {
            continue;
        }
        if (last == 0) {
            last = p.first;
            if (p.second >= 4) {
                cout << last * last << "\n";
                return;
            }
        } else {
            cout << last * p.first << "\n";
            return;
        }
    }
    cout << 0 << "\n";


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
