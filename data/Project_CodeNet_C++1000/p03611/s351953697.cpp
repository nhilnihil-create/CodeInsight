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
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        um[a]++;
        um[a - 1]++;
        um[a + 1]++;
    }
    int res = 0;
    for (auto p : um) {
        res = max(res, p.second);
    }
    cout << res << endl;
}


