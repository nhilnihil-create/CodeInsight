#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <limits>
#include <random>
#include <complex>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

#define REP(i,n) for (int i = 0; i < n; i++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long ll;

ll N;
char op[100010];
ll A[100010];
ll dp[3][100010];

int main ()
{
    cin >> N;
    op[0] = '+';
    cin >> A[0];
    REP(i,N - 1) {
        cin >> op[i + 1] >> A[i + 1];
    }

    REP(i,3)REP(j,100010) dp[i][j] = -1e18;
    dp[0][1] = A[0];

    for (int i = 1; i < N; i++) {
        if (op[i] == '+') {
            dp[0][i + 1] = dp[0][i] + A[i];
            dp[1][i + 1] = dp[1][i] - A[i];
            dp[2][i + 1] = dp[2][i] + A[i];
        } else {
            dp[0][i + 1] = dp[1][i] + A[i];
            dp[1][i + 1] = max(dp[0][i], dp[2][i]) - A[i];
            dp[2][i + 1] = dp[1][i] + A[i];
        }
        dp[1][i + 1] = max(dp[1][i + 1], dp[2][i + 1]);
        dp[0][i + 1] = max(dp[0][i + 1], dp[1][i + 1]);
    }

    ll ans = 0;
    REP(i,3) ans = max(ans, dp[i][N]);
    cout << ans << endl;

    return 0;
}
