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
// 70 12 34

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
    if (n < 10) {
        cout << "Yes" << "\n";
    }
    auto l  =to_string(n);
    for (int i = 0; i < l.size(); ++i) {
        if (l[i] != l[l.size() - 1 - i]) {
            cout << "No" << "\n";
            return;
        }
    }
    cout << "Yes" << "\n";
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
