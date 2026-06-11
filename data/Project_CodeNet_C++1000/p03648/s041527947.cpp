#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

// inf
constexpr ll infl = 10000000000000000LL;
constexpr int inf = 1000000000;

int main() {
    ll k;
    cin >> k;
    constexpr int n = 50;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + k / n;
    }

    int i = 0;
    for (int j = 0; j < k % n; ++j) {
        a[i] += n;
        for (int k = 0; k < n; ++k) {
            if (k != i)
                a[k] -= 1;
        }
        ++i;
    }

    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i < n - 1)
            cout << ' ';
        else
            cout << endl;
    }

    return 0;
}