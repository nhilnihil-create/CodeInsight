#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    int w, h;
    cin >> w >> h;

    vector<pair<ll, bool>> v;
    for (int i = 0; i < w; i++) {
        int p;
        cin >> p;
        v.emplace_back(p, true);
    }
    for (int i = 0; i < h; i++) {
        int q;
        cin >> q;
        v.emplace_back(q, false);
    }
    sort(v.begin(), v.end());

    ll ret = 0;
    for (auto x:v) {
        if (x.second) {
            ret += x.first * (h + 1);
            w--;
        } else {
            ret += x.first * (w + 1);
            h--;
        }
    }

    cout << ret << endl;
    return 0;
}