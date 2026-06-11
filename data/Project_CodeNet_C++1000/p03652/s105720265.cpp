#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <random>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int ans = n;
    while (!a[0].empty()) {
        vector<int> cnt(m);
        for (auto t : a) {
            cnt[t[0]]++;
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> toer;
        for (int i = 0; i < m; i++) {
            if (cnt[i] == mx) toer.push_back(i);
        }
        ans = min(ans, mx);
        for (auto &t : a) {
            for (auto x : toer) {
                t.erase(find(t.begin(), t.end(), x));
            }
        }
    }
    cout << ans << endl;
}   
