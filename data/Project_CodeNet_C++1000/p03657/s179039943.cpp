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


int gcd(int a, int b) {
    while (b != 0) {
        auto na = a % b;
        a = b;
        b = na;
    }
    return a;
}


void oneCase() {
    int a, b;
    cin >> a >> b;
    if (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) {
        cout << "Possible" << "\n";
    } else {
        cout << "Impossible" << "\n";
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
