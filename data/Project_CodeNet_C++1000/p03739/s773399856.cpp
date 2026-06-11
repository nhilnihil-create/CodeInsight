#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    
    long long ans = 1e18;
    long long sum, res;
    
    sum = 0;
    res = 0;
    rep(i, n) {
        sum += a[i];
        if (i % 2) {
            if (sum >= 0) {
                res += (1 + sum);
                sum = -1;
            }
        } else {
            if (sum <= 0) {
                res += (1 - sum);
                sum = 1;
            }
        }
    }
    ans = min(ans, res);
    sum = 0;
    res = 0;
    rep(i, n) {
        sum += a[i];
        if (i % 2 == 0) {
            if (sum >= 0) {
                res += (1 + sum);
                sum = -1;
            }
        } else {
            if (sum <= 0) {
                res += (1 - sum);
                sum = 1;
            }
        }
    }
    ans = min(ans, res);
    
    cout << ans << endl;
    return 0;
}
