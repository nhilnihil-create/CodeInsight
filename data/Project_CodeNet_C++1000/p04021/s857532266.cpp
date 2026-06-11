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
    int n;
    cin >> n;
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vp.emplace_back(a, i);
    }
    sort(vp.begin(), vp.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(i - vp[i].second) % 2;
    }
    cout << res / 2 << endl;
}


