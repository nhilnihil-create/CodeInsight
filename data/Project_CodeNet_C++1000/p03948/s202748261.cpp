#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
#include <map>
#include <stack>
#define REP(i,n) for(long (i)=0;(i)<(n);(i)++)
#define INF numeric_limits<double>::infinity()
constexpr long MOD = 1e9 + 7;
using namespace std;

int main() {
    int n, t, a;
    cin >> n >> t;
    
    vector<int> as;
    
    REP(i,n) {
        cin >> a;
        as.push_back(a);
    }

    vector<int> v = vector<int>(n, 0);
    
    v[n-1] = as[n-1];
    
    for (int i = n - 2; i >= 0; i--) {
        v[i] = max(v[i+1], as[i]);
    }
    
    int df = 0;
    REP(i,n) {
        df = max(df, v[i] - as[i]);
    }
    
    int ans = 0;
    REP(i,n) {
        if (v[i] - as[i] == df) {
            ans++;
        }
    }
    
    cout << ans << endl;
}
