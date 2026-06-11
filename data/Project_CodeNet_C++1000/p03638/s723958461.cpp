#include <algorithm>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using Graph = std::vector<std::vector<int>>;
using WGraph = std::vector<std::vector<std::pair<int, long long>>>;
using ll = long long;
using namespace std;

int main() {
    int h = 0, w = 0;
    cin >> h >> w;
    int n = 0;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a.at(i);
    }
    vector<vector<int>> ans(h, vector<int>(w));
    int cnt = 0;
    int paint = 0;
    bool rev = false;
    int cur_raw = 0;
    auto cur = ans.at(0).begin(), fin = ans.at(0).end();
    while (true) {
        *cur = paint + 1;
        cnt++; 
        if (rev) cur--;
        else cur++;
        if (cnt == a.at(paint)) {
            paint++;
            cnt = 0;
        }
        if (cur == fin) {
            cur_raw++;
            if (cur_raw == h) break;
            if (rev) {
                cur = ans.at(cur_raw).begin(), fin = ans.at(cur_raw).end();
            } else {
                cur = ans.at(cur_raw).end()-1, fin = ans.at(cur_raw).begin()-1;
            }
            rev = !rev;
        }
    }
    for (auto v : ans) {
        for (int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
 