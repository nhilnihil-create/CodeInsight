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
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++ ) {
        int a, b;
        cin >> a >> b;
        vp.emplace_back(a, b);
    }
    sort(vp.begin(), vp.end());
    cout << vp.back().first + vp.back().second << endl;
}


