#include <iostream>
#include <utility>
#include <tuple>
#include <string>
#include <cstdint>
#include <vector>
#include <array>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;
using i64 = int64_t;
int n;
vector<int> x;
int main() {
    cin >> n;
    x.resize(n + 1);
    vector<int> res(n * n);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
        res[x[i] - 1] = i;
    }
    if (n == 1) {
        cout << "Yes\n1\n";
        return 0;
    }
    vector<pair<int, int>> ps;
    for (int i = 1; i <= n; ++i) {
        ps.emplace_back(x[i], i);
    } 
    sort(begin(ps), end(ps));
    bool f = false;
    for (int i = 0, j = 0, k = -1; i < n * n; ++i) {
        while (j == 0) {
            k++;
            if (k == n) {
                k = 0;
                f = true;
            }
            if (!f) j = ps[k].second - 1;
            else j = n - ps[k].second;
        }
        cerr << k << endl;
        if (res[i] == 0) {
            res[i] = ps[k].second;
            --j;
        }

    }
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = x[i] - 1; j >= 0; --j) {
            cnt += res[j] == i;
        }
        cerr << i << ' ' << cnt << endl;
        if (cnt != i) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    for (int y : res) cout << y << ' ';
    cout << '\n';
    return 0;
}