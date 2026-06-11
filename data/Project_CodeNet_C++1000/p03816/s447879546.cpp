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
    sort(v.begin(), v.end());
    vector<int> dup;
    for (int i = 1; i < n; i++) {
        if (v[i] == v[i - 1]) {
            dup.push_back(v[i]);
        }
    }
    if (dup.size() % 2 == 0) {
        cout << n - dup.size() << endl;
    } else {
        cout << n - dup.size() - 1 << endl;
    }
}


