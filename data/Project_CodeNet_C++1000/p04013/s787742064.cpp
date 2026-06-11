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
    int a;
    cin >> a;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<long long int>> res(n + 1, vector<long long int>(n * 50 + 1, 0));
    res[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            for (int k = 0; k + v[i] <= n * 50; k++) {
                res[j + 1][k + v[i]] += res[j][k];
            }
        }
    }
    long long int r = 0;
    for (int i = 1; i <= n; i++) {
        r += res[i][i * a];
    }
    cout << r << endl;
}


