#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const long long INF = 1e18;
int n, m, r;
vector< vector<long long> > dp(220, vector<long long>(220, INF));

int main() {
    cin >> n >> m >> r;
    vector<int> R(r, 0);
    for(int i = 0; i < r; ++i) {
        cin >> R.at(i); R.at(i)--;
    }

    for(int i = 0; i < m; ++i) {
        int aa, bb; long long cc;
        cin >> aa >> bb >> cc;
        aa--; bb--;
        dp[aa][bb] = cc;
        dp[bb][aa] = cc;
    }

    for(int i = 0; i < n; ++i) dp[i][i] = 0;

    for(int k = 0; k < n; ++k) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                chmin(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    long long ans = INF;
    sort(R.begin(), R.end());
    do {
        long long sum = 0;
        int pre = R.at(0);
        for(int i = 1; i < r; ++i) {
            // cout << "root " << pre << " " << R.at(i) << endl;
            sum += dp[pre][R.at(i)];
            pre = R.at(i);
        }
        chmin(ans, sum);
    }while(next_permutation(R.begin(), R.end()));

    cout << ans << endl;
}