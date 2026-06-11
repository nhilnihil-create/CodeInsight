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
    long long int x;
    cin >> x;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> min_cost(n, vector<int>(n, 0x3f3f3f3f));
    for (int i = 0; i < n; i++) {
        int m = 0x3f3f3f3f;
        for (int j = 0; j < n; j++) {
            m = min(m, v[(i + j) % n]);
            min_cost[i][j] = m;
        }
    }
    long long int res = -1;
    long long int base = 1;
    for (int i = 0; i < n; i++) {
        long long int r = x * i;
        for (int j = 0; j < n; j++) {
            r += min_cost[j][i];
        }
        if (res == -1 || res > r) {
            res = r;
        }
    }
    cout << res << endl;
}


