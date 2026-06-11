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
#include <utility>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000007LL;
constexpr int inf = 1000000007;

int main() {
    int n;
    cin >> n;
    int k = 0;
    int a[2] = {};
    int cnt[2] = {};
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;

        if (b != a[0] && b != a[1]) {
            if (k == 2) {
                cout << "No" << endl;
                return 0;
            } else {
                a[k++] = b;
            }
        }

        if (b == a[0]) {
            ++cnt[0];
        } else {
            ++cnt[1];
        }
    }

    if (k == 1) {
        cout << (2 * a[0] <= n || a[0] == n - 1 ? "Yes" : "No") << endl;
    } else {
        if (a[0] > a[1]) {
            swap(a[0], a[1]);
            swap(cnt[0], cnt[1]);
        }
        if (a[1] - a[0] > 1 || cnt[1] == 1) {
            cout << "No" << endl;
            return 0;
        }

        cout << (cnt[0] <= a[0] && a[1] <= cnt[0] + cnt[1] / 2 ? "Yes" : "No") << endl;
    }
    return 0;
}