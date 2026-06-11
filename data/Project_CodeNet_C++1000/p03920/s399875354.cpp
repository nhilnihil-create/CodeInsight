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
#include <cassert>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    int n;
    cin >> n;
    int k = 0;
    while (true) {
        if (k * (k + 1) / 2 >= n) {
            break;
        }
        ++k;
    }
    for (int i = k; i > 0; --i) {
        if (i <= n) {
            cout << i << "\n";
            n -= i;
        }
    }
    return 0;
}
