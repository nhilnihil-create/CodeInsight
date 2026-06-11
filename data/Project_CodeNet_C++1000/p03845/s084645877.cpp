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
    vector<int> vt(n + 1, 0);
    int s = 0;
    for (int i = 1; i <= n; i++) {
        cin >> vt[i];
        s += vt[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int p, x;
        cin >> p >> x;
        cout << s - vt[p] + x << endl;
    }
}


