#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, x;
    cin >> N >> x;
    if (x == 1 || x == 2 * N - 1) {
        cout << "No\n";
        return 0;
    }
    if (N == 2) {
        cout << "Yes\n1\n2\n3\n";
        return 0;
    }
    vector<int> ans(2 * N - 1);
    if (x == 2) {
        int cnt = 1;
        rep(i, 2 * N - 1) {
            if (i == N - 3) {
                ans[i] = 3;
            } else if (i == N - 2) {
                ans[i] = 1;
            } else if (i == N - 1) {
                ans[i] = 2;
            } else if (i == N) {
                ans[i] = 4;
            } else if (i == N + 1) {
                ans[i] = 5;
            } else {
                while (cnt == 1 || cnt == 2 || cnt == 3 || cnt == 4 || cnt == 5) ++cnt;
                ans[i] = cnt;
                ++cnt;
            }
        }
    } else {
        int cnt = 1;
        rep(i, 2 * N - 1) {
            if (i == N - 3) {
                ans[i] = x - 1;
            } else if (i == N - 2) {
                ans[i] = x + 1;
            } else if (i == N - 1) {
                ans[i] = x;
            } else if (i == N) {
                ans[i] = x - 2;
            } else {
                while (cnt == x - 1 || cnt == x + 1 || cnt == x || cnt == x - 2) ++cnt;
                ans[i] = cnt;
                ++cnt;
            }
        }
    }
    cout << "Yes\n";
    rep(i, 2 * N - 1) cout << ans[i] << "\n";
    return 0;
}
