
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
    
    int n, l;
    cin >> n >> l;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> res;
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] + v[i + 1] >= l) {
            flag = i + 1;
            break;
        }
    }
    if (flag == 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (i != flag) {
            res.push_back(i);
        } else {
            break;
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if (i != flag) {
            res.push_back(i);
        } else {
            break;
        }
    }
    res.push_back(flag);
    cout << "Possible" << endl;
    for (auto r : res) {
        cout << r << endl;
    }
}
