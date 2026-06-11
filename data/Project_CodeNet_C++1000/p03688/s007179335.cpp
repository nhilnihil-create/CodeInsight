
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
    int n1 = *max_element(v.begin(), v.end());
    int n2 = *min_element(v.begin(), v.end());
    if (abs(n1 - n2) == 0) {
        if (n1 * 2 <= n || n1 + 1 == n)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return 0;
    }
    if (abs(n1 - n2) > 1) {
        cout << "No" << endl;
        return 0;
    }
    int c1 = count(v.begin(), v.end(), n1);
    int c2 = count(v.begin(), v.end(), n2);
    if (n1 - c2 <= c1 / 2 && n1 - c2 > 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
