#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <cassert>
#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define REPI(i,a,b) for(long (i)=(a);(i)<(b);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 998244353;
using namespace std;
using P = pair<long, long>;
using VI = vector<long>;

int main() {
    long i, o, t, j, l, s, z;
    cin >> i >> o >> t >> j >> l >> s >> z;
    // only use i, o, j, l
    
    if (j && l && i) {
        // can make jli
        long j2, l2, i2;
        j2 = j - 1;
        l2 = l - 1;
        i2 = i - 1;
        long ans = 3;
        ans += l2 / 2 * 2 + i2 / 2 * 2 + j2 / 2 * 2 + o;
        
        long ans2 = i / 2 * 2 + l / 2 * 2 + j / 2 * 2 + o;
        cout << max(ans, ans2) << endl;
        return 0;
    } else {
        cout << i / 2 * 2 + l / 2 * 2 + j / 2 * 2 + o << endl;
    }
}
