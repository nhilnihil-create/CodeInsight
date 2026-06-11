#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000000LL;
constexpr int inf = 1000000000;

int main() {
    int n, x;
    cin >> n >> x;
    if (x == 1 || x == 2 * n - 1) {
        cout << "No" << endl;
    } else if (n == 2) {
        cout << "Yes" << endl;
        cout << 1 << endl;
        cout << 2 << endl;
        cout << 3 << endl;
    } else {
        cout << "Yes" << endl;
        set<int> used;
        vector<int> ans(2 * n - 1);
        if (x == 2) {
            ans[n - 2] = x + 1;
            ans[n - 1] = x - 1;
            ans[n] = x;
            ans[n + 1] = x + 2;
            used.insert(x + 1);
            used.insert(x - 1);
            used.insert(x);
            used.insert(x + 2);
        } else {
            ans[n - 2] = x - 1;
            ans[n - 1] = x;
            ans[n] = x + 1;
            ans[n + 1] = x - 2;
            used.insert(x + 1);
            used.insert(x - 1);
            used.insert(x);
            used.insert(x - 2);
        }

        int j = 1;
        for (int i = 0; i < 2 * n - 1; ++i) {
            if (ans[i] == 0) {
                while (used.count(j)) {
                    ++j;
                }
                ans[i] = j;
                used.insert(j);
            }
        }

        for (int k : ans) {
            cout << k << endl;
        }
    }
    return 0;
}