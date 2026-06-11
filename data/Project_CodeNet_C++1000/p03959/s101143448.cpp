#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vt(n, 0), va(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> vt[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> va[i];
    }
    vector<pair<int, int>> vp(n, make_pair(1, 0x3f3f3f3f));
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (vt[i] > last) {
            vp[i].first = vt[i];
            vp[i].second = vt[i];
        }
        vp[i].second = vt[i];
        last = vt[i];
    }
    last = 0;
    for (int i = n - 1; i >= 0; i-- ) {

        if (va[i] > last) {   
            if (vp[i].first > va[i] || vp[i].second < va[i]) {
                cout << 0 << endl;
                return 0;
            }
            vp[i].first = va[i];
            vp[i].second = va[i];
        }
        vp[i].second = min(vp[i].second, va[i]);
        last = va[i];
    }
    long long int res = 1;
    const int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        res = res * (vp[i].second - vp[i].first + 1);
        res %= mod;
    }
    cout << res << endl;
}
