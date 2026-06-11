#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    vector<int> mxs{399, 799, 1199, 1599, 1999, 2399, 2799, 3199, 999999};

    auto index = [&](int x) {
        for (int i = 0; i < mxs.size(); ++i) {
            if (x <= mxs[i]) {
                return i;
            }
        }
        return -1;
    };

    int m = mxs.size();
    int n;
    cin >> n;
    vector<int> cnts(m, 0);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnts[index(x)];
    }

    int mn = 0, mx = 0;
    if (cnts.back() == 0) {
         for (auto x : cnts) {
            if (x > 0)  {
                ++mn;
            }
         }
         mx = mn;
    } else if (cnts.back() == n) {
        mn = 1;
        // mx = min(m - 1, n);
        mx = n;
    } else {
        for (int i = 0; i < m - 1; ++i) {
            if (cnts[i] > 0) {
                ++mn;
            }
        }
        // mx = min(mn + cnts.back(), m - 1);
        mx = mn + cnts.back();
    }

    cout << mn << " " << mx << '\n';


    return 0;
}