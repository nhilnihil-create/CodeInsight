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
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long int c = 0, res = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            res += c / 2 * 2;
            c = 0;
        } else {
            c += v[i];
        }
    }
    res += c / 2 * 2;
    cout << res / 2 << endl;
}


