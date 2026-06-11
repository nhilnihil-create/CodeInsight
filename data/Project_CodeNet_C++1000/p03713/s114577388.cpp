/**
 *    author:  FromDihPout
 *    created: 2020-07-28
**/

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

long long min_diff(long long h, long long w) {
    long long diff1 = (h % 3 != 0) * w;
    
    long long w1 = w / 2, w2 = (w + 1) / 2;
    long long l = 0, r = h, diff2 = INF;
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long a1 = mid * w, a2 = (h - mid) * w1, a3 = (h - mid) * w2;
        diff2 = min(diff2, max({a1, a2, a3}) - min({a1, a2, a3}));
        
        if (a1 > max(a2, a3)) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return min(diff1, diff2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long h, w;
    cin >> h >> w;
    
    cout << min(min_diff(h, w), min_diff(w, h)) << '\n';
    return 0;
}