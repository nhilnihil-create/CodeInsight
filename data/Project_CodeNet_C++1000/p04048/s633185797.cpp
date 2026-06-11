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

ll rec(ll a, ll b) {
    if (a == b) return a;
    if (b % a == 0) return 2 * a * (b / a) - a;
    return 2 * a * (b / a) + rec(b % a, a);
}

int main() {
    ll N, X;
    cin >> N >> X;
    if (2 * X < N) {
        cout << 2 * X + N + rec(N - 2 * X, X) << "\n";
    } else if (2 * X == N) {
        cout << 3 * X << "\n";
    } else {
        cout << N + rec(X, N - X) << "\n";
    }
    return 0;
}
