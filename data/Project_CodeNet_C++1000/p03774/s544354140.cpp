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
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(N), C(M), D(M);
    REP(i, N) cin >> A[i] >> B[i];
    REP(i, M) cin >> C[i] >> D[i];
    REP(i, N) {
        int ans = 0;
        ll d = INF;
        REP(j, M) {
            if (abs(A[i] - C[j]) + abs(B[i] - D[j]) < d) {
                ans = j + 1;
                d = abs(A[i] - C[j]) + abs(B[i] - D[j]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
