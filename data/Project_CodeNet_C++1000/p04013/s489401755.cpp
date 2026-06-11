#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
#include <list>
#include <deque>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll MOD = 1000000007;
ll INF = 1LL << 60;


long long dp[55][3000][55];
int main() {
    int N, A;
    cin >> N >> A;
    vector<int> x(N);
    for (int i = 0; i < N; ++i) cin >> x[i];

    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int s = 0; s <= N*A; ++s) {
            for (int k = 0; k <= N; ++k) {
                if (dp[i][s][k] == 0) continue;
                dp[i+1][s][k] += dp[i][s][k];
                dp[i+1][s+x[i]][k+1] += dp[i][s][k];
            }
        }
    }
    long long res = 0;
    for (int k = 1; k <= N; ++k) res += dp[N][A*k][k];
    cout << res << endl;
}