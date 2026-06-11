#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, h; cin >> w >> h;
    long long ans = 0;
    vector<pair<long long, int>> v;
    for (int i = 0; i < w; i++) {
        long long p; cin >> p;
        v.emplace_back(p, 0);
    }
    for (int i = 0; i < h; i++) {
        long long q; cin >> q;
        v.emplace_back(q, 1);
    }
    sort(v.begin(), v.end());
    for (auto x: v) {
        int type = x.second;
        long long d = x.first;
        if (type) {
            if (w >= 0) ans += d * (w+1);
            h--;
        } else {
            if (h >= 0) ans += d * (h+1);
            w--;
        }
    } 
    cout << ans << endl;
    return 0;
}