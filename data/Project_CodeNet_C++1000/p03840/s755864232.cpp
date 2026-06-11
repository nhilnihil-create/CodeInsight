#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#include <functional>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
using lint = int64_t;

int main() {
    lint I, O, T, J, L, S, Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;
    lint ans = I / 2 * 2 + O + J / 2 * 2 + L / 2 * 2;
    if (I > 0 && J > 0 && L > 0) ans = max(ans, 3 + (I - 1) / 2 * 2 + O + (J - 1) / 2 * 2 + (L - 1) / 2 * 2);
    cout << ans << "\n";
    return 0;
}

//
//
//
//
//
//
//
// ........................//
