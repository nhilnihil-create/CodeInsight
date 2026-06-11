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
    vector<int> v(10001, 0);
    v[0] = 1;
    int s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 10000; j - s >= 0; j--) {
            v[j] = max(v[j], v[j - s]);
        }
    }
    int res = 0;
    for (int i = 0; i <= 10000; i++) {
        if (i % 10 != 0 && v[i] > 0) {
            res = max(i, res);
        }
    }
    cout << res << endl;
}


