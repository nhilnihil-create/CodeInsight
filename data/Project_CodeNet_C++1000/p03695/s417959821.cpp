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
    vector<int> v(9, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[min(8, a / 400)]++;
    }
    int res = 0;
    for (int i = 0; i <= 7; i++) {
        if (v[i] > 0) res++;
    }
    if (v[8] > 0) {
        cout << min(8, max(1, res)) << " " << res + v[8] << endl;
    } else {
        cout << res << " " << res << endl;
    }
}


