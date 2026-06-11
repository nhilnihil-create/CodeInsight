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
    string line1;
    string line2;
    cin >> line1 >> line2;
    vector<ll> cnt;
    if (line1[0] == line2[0]) {
        cnt.push_back(3);
    } else {
        cnt.push_back(6);
    }

    int mod = 1e9 + 7;

    for (int l = 1; l < n; ++l) {
        if (line1[l] == line1[l - 1]) {
            continue;
        }
        if (line1[l - 1] == line2[l - 1]) {
            cnt.push_back((cnt.back() * 2) % mod);
        } else {
            if (line1[l] == line2[l]) {
                cnt.push_back(cnt.back());
            } else {
                cnt.push_back((cnt.back() * 3) % mod);
            }
        }
    }

    cout << cnt.back() % mod << "\n";



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
