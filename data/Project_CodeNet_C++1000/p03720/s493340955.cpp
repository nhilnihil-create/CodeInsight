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
    vector<int> res(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >>  b;
        res[a]++;
        res[b]++;
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << endl;
    }
}


