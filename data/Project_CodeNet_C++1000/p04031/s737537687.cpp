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
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++ ) {
        cin >> v[i];
    }
    int res = 0x3f3f3f3f;
    for (int i = -100; i <= 100; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) {
            c += pow(i - v[j], 2);
        }
        res = min(res, c);
    }
    cout << res << endl;
}
