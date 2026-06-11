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
    long long int a, b;
    cin >> a >> b;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    long long int res = 0;
    for (int i = 1; i < n; i++) {
        res += min(b, a * (v[i] - v[i - 1]));
    }
    cout << res << endl;
}


