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
    long long int res, t;
    res = 1;
    for (int i = 0; i < n; i++) {
        cin >> t;
        res /= gcd(res, t);
        res *= t;
    }
    cout << res << endl;
}


