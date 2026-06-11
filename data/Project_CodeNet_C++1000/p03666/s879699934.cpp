#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    b -= a;
    a = 0;
    if (b < 0) b *= -1;
    for (int cnt1 = 0; cnt1 <= n - 1; cnt1++) {
        int cnt2 = n - 1 - cnt1;
        int base = c * (cnt1 - cnt2);
        int mx = (cnt1 * abs(d - c));
        int mn = (cnt2 * abs(d - c));
        if (base - mn <= b && b <= base + mx) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
 
}   
