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
    int n, k;
    cin >> n >> k;
    long long int res = k;
    for (int i = 1; i < n; i++) {
        res *= (k - 1);
    }
    cout << res << endl;
}
