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
    int h, w;
    cin >> h >> w;
    vector<int> acnt(26);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char c;
            cin >> c;
            ++acnt[c - 'a'];
            acnt[c - 'a'] %= 4;
        }
    }

    int cnt[4];
    for (int i = 0; i < 26; ++i) {
        ++cnt[acnt[i]];
    }

    if (h % 2 != w % 2) {
        int even = h % 2 == 0 ? h : w;
        cout << (cnt[1] == 0 && cnt[2] <= even / 2 && cnt[3] == 0 ? "Yes" : "No") << endl;
    } else if (h % 2 == 0) {
        cout << (cnt[1] == 0 && cnt[2] == 0 && cnt[3] == 0 ? "Yes" : "No") << endl;
    } else {
        cout << (cnt[1] == 1 && (cnt[2] <= h / 2 + w / 2) && cnt[3] == 0 ? "Yes" : "No") << endl;
    }
    return 0;
}