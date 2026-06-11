#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <climits>
#include <cassert>
#include <algorithm>
#include <utility>

using namespace std;
using Int = long long int;
using UInt = unsigned long long int;
using VI = vector<long long int>;
using VVI = vector<vector<long long int> >;

int main(void) {
    Int n, k;
    cin >> n >> k;
    Int cnt = k;
    for (Int i = 1; i < n; ++i) {
        cnt *= (k - 1);
    }
    cout << cnt << endl;
    return 0;
}

