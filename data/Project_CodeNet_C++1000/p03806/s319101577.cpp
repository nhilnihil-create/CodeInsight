#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = (int)1e9 + 7;
template<class T> inline bool chmin(T &a, T b) { return a > b ? (a = b, 1) : 0; }

int main() {
    const int MAX = 400;
    int n; cin >> n;
    int ma, mb; cin >> ma >> mb;
    vector<vector<int>> dp(MAX + 1, vector<int>(MAX + 1, INF));
    dp[0][0] = 0;
    while (n--) {
        int a, b, c; cin >> a >> b >> c;
        for (int na = MAX; na >= a; na--) {
            for (int nb = MAX; nb >= b; nb--) {
                chmin(dp[na][nb], dp[na - a][nb - b] + c);
            }
        }
    }
    int mi = INF;
    for (int a = 1; a <= MAX; a++) for (int b = 1; b <= MAX; b++) {
        if (a * mb == b * ma) chmin(mi, dp[a][b]);
    }
    cout << (mi == INF ? -1 : mi) << endl;
    return 0;
}
