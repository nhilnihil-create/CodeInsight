#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (a); i > (b); i--)
#define ALL(a) (a).begin(), (a).end()
#define INF 1000000001

int N, A[300][300];

int main() {
    cin >> N;
    REP(i, N) REP(j, N) cin >> A[i][j];
    REP(k, N) REP(i, N) REP(j, N) {
        if (A[i][j] > A[i][k] + A[k][j]) {
            cout << -1 << endl;
            return 0;
        }
    }
    REP(k, N) REP(i, N) REP(j, N) {
        if (i != j && j != k && k != i && A[i][j] == A[i][k] + A[k][j]) {
            A[i][j] = A[j][i] = INF;
        }
    }
    ll ans = 0;
    REP(i, N) REP(j, N) if (A[i][j] != INF) ans += A[i][j];
    cout << ans / 2 << endl;
    return 0;
}