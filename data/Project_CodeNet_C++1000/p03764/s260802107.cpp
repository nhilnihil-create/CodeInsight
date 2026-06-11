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
    vector<long long int> v1(n, 0), v2(m, 0);
    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
    }
    long long int s1 = 0, s2 = 0;
    const int mod = 1e9 + 7;
    for (int i = 0; i + 1 < n; i++) {
        s1 += (v1[i + 1] - v1[i]) * (i + 1) * (n - i - 1);
        s1 %= mod;
    }
    for (int i = 0; i + 1 < m; i++) {
        s2 += (v2[i + 1] - v2[i]) * (i + 1) * (m - i - 1);
        s2 %= mod;
    }
    cout << s1 * s2 % mod << endl;
}
