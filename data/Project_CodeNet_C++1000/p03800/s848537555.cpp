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

bool print_if_valid(const vector<int> &ans, const string &s) {
    if (s.front() == 'o') {
        if (ans.front() == 0) {
            if (ans[1] != ans.back())
                return false;
        } else {
            if (ans[1] == ans.back())
                return false;
        }
    } else {
        if (ans.front() == 0) {
            if (ans[1] == ans.back())
                return false;
        } else {
            if (ans[1] != ans.back())
                return false;
        }
    }

    if (s.back() == 'o') {
        if (ans.back() == 0) {
            if (ans[0] != ans[ans.size() - 2])
                return false;
        } else {
            if (ans[0] == ans[ans.size() - 2])
                return false;
        }
    } else {
        if (ans.back() == 0) {
            if (ans[0] == ans[ans.size() - 2])
                return false;
        } else {
            if (ans[0] != ans[ans.size() - 2])
                return false;
        }
    }

    for (int k : ans) {
        cout << (k == 0 ? 'S' : 'W');
    }
    cout << endl;
    return true;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    // 0: 羊 1: 狼
    for (int i = 0; i < 4; ++i) {
        vector<int> ans(n);
        ans[0] = i >> 0 & 1;
        ans[1] = i >> 1 & 1;
        for (int j = 2; j < n; ++j) {
            if ((ans[j - 1] == 0 && s[j - 1] == 'o') || (ans[j - 1] == 1 && s[j - 1] == 'x')) {
                ans[j] = ans[j - 2];
            } else {
                ans[j] = ans[j - 2] ^ 1;
            }
        }
        if (print_if_valid(ans, s))
            return 0;
    }
    cout << -1 << endl;
    return 0;
}