#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;

int main() {
    long n, m;
    long x, y, c;
    vector<long> xs, ys;
    cin >> n >> m;
    cin >> c;
    REP(i,n-1) {
        cin >> x;
        xs.push_back(x-c);
        c = x;
    }
    cin >> c;
    REP(i,m-1) {
        cin >> y;
        ys.push_back(y-c);
        c = y;
    }
    
    x = 0;
    y = 0;
    vector<long> ks;
    long t = n - 1;
    ks.push_back(t);
    REP(i,(t-1)/2) {
        ks.push_back(ks.back() + t - 2 - 2 * i);
    }
    REP(i,t/2) {
        ks.push_back(ks[t/2 - i - 1]);
    }
    REP(i,t) {
        x += ks[i] * xs[i];
        x %= MOD;
    }
    
    vector<long> ks2;
    t = m - 1;
    ks2.push_back(t);
    REP(i,(t-1)/2) {
        ks2.push_back(ks2.back() + t - 2 - 2 * i);
    }
    REP(i,t/2) {
        ks2.push_back(ks2[t/2 - i - 1]);
    }
    REP(i,t) {
        y += ks2[i] * ys[i];
        y %= MOD;
    }
    
    cout << x * y % MOD << endl;
}

