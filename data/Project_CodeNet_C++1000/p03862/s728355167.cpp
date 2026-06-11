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
    int n, x;
    cin >> n >> x;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long int res = 0;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] >= x) {
            res += v[i];
            res += v[i - 1] - x;
            v[i] = 0;
        } else if (v[i] + v[i - 1] > x) {
            res += v[i] + v[i - 1] - x;
            v[i] -= v[i] + v[i - 1] - x;
        } 
    }
    cout << res << endl;
}


