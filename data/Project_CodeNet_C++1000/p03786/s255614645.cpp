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
    vector<long long int> v1(n, 0), v2(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());
    v2[0] = v1[0];
    for (int i = 1; i < n; i++) {
        v2[i] = v2[i - 1] + v1[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        if (2 * v2[i] < v1[i + 1]) {
            cout << n - i - 1 << endl;
            return 0;
        }
    }
    cout << n << endl;
}


