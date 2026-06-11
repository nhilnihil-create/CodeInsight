#include <bits/stdc++.h>
using namespace std;

int main() {
    int w, h;
    cin >> w >> h;
    vector<pair<long, int>> dat;
    for (int i = 0; i < w; i++) {
        long e;
        cin >> e;
        dat.emplace_back(e, 0);
    }
    for (int i = 0; i < h; i++) {
        long e;
        cin >> e;
        dat.emplace_back(e, 1);
    }
    
    sort(dat.begin(), dat.end());
    
    long ans = 0;
    for (const auto &e : dat) {
        long cost; int type;
        tie(cost, type) = e;
        if (type == 0) {
            ans += (long)(h + 1) * cost;
            w--;
        } else {
            ans += (long)(w + 1) * cost;
            h--;
        }
    }
    
    cout << ans << endl;
    return 0;
}