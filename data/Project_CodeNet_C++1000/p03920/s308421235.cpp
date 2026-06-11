#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define int long long
#define rep(n, i) for (int i = 0; i < n; i++)
#define rep2(m, n, i) for (int i = m; i < n; i++)
#define rep_r(n, i) for (int i = n - 1; i >= 0; i--)

const int INF = 1LL << 60;
const int MOD = 1e9 + 7;
const int MAX = 1e4;

signed main() {
    int tri[MAX];
    tri[0] = 0;
    rep2(1, MAX, i) {
        tri[i] = tri[i - 1] + i;
    }
    int n;
    cin >> n;
    int max_p = 1;
    while (true) {
        if (tri[max_p] > n) {
            max_p--;
            break;
        }
        max_p++;
    }
    int diff = n - tri[max_p];
    int start_1 = max_p - diff + 1;
    rep2(1, start_1, i) {
        cout << i << endl;
    }
    rep2(start_1, max_p + 1, i) {
        cout << i + 1 << endl;
    }
    return 0;
}