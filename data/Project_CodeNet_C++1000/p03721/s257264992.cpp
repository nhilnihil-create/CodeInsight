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
    long long int n, k;
    cin >> n >> k;
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vp.push_back(make_pair(a, b));
    }
    sort(vp.begin(), vp.end());
    for (auto p : vp) {
        k -= p.second;
        if (k <= 0) {
            cout << p.first << endl;
            return 0;
        }
    }
}


