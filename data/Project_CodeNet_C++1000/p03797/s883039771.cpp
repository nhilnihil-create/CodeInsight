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
#include <cctype>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    ll N, M;
    cin >> N >> M;
    if (M < 2 * N) {
        cout << M / 2 << "\n";
    } else {
        cout << N + (M - 2 * N) / 4 << "\n";
    }
    return 0;
}
