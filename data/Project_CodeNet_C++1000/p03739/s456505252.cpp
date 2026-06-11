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
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int last = 1;
    long long int res = 0;
    if (v[0] <= 0) res = abs(1 - v[0]);
    else last = v[0];
    int target;
    for (int i = 1; i < n; i++) {
        if (last > 0) {
            target = -1;
        } else {
            target = 1;
        }
        last += v[i];
        if (target == 1) {
            if (last <= 0) {
                res += abs(1 - last);
                last = 1;
            }
        } else {
            if (last >= 0) {
                res += abs(-1 - last);
                last = -1;
            }
        }
    }

    long long int next_res = 0;
    last = -1;
    if (v[0] >= 0) next_res = abs(-1 - v[0]);
    else
        last = v[0];
    for (int i = 1; i < n; i++) {
        if (last > 0) {
            target = -1;
        } else {
            target = 1;
        }
        last += v[i];
        if (target == 1) {
            if (last <= 0) {
                next_res += abs(1 - last);
                last = 1;
            }
        } else {
            if (last >= 0) {
                next_res += abs(-1 - last);
                last = -1;
            }
        }
    }
    // cout << res << " " << next_res << endl;
    cout << min(res, next_res) << endl;
}
