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
    int n, k;
    cin >> n >> k;
    vector<int> v(10, 0);
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        v[t]++;
    }
    for (int i = n; ; i++) {
        string s = to_string(i);
        int flag = 1;
        for (auto ss : s) {
            if (v[ss - '0'] == 1) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cout << i << endl;
            return 0;
        }
    }
}
