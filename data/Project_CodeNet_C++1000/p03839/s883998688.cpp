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
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    REP(i, N) {
        cin >> A[i];
        B[i] = max(A[i], 0LL);
    }
    vector<ll> ASUM(N + 1, 0), BSUM(N + 1, 0);
    REP(i, N) {
        ASUM[i + 1] = ASUM[i] + A[i];
        BSUM[i + 1] = BSUM[i] + B[i];
    }
    ll ans = 0;
    REP(i, N - K + 1) {
        ans = max(ans, BSUM[i] + BSUM[N] - BSUM[i + K] + max(0LL, ASUM[i + K] - ASUM[i]));
    }
    cout << ans << "\n";
    return 0;
}
