#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {  
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vn, vm;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vn.push_back(make_pair(a, b));
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vm.push_back(make_pair(a, b));
    }
    for (int i = 0; i < n; i++) {
        int d = 0x3f3f3f3f;
        int res = -1;
        for (int j = 0; j < m; j++) {
            int dd = abs(vn[i].first - vm[j].first) + abs(vn[i].second - vm[j].second);
            if (dd < d) {
                res = j;
                d = dd;
            }
        }
        cout << res + 1 << endl;
    }
}


