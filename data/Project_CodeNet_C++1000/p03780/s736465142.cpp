#include <bits/stdc++.h>

using namespace std;
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<vector<char>> dp1(N + 1, vector<char>(K + 1));
    vector<vector<char>> dp2(N + 1, vector<char>(K + 1));
    vector<vector<short>> acc(N + 1, vector<short>(K + 2));

    dp1[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= K; j++) {
            if (!dp1[i][j]) continue;
            dp1[i + 1][j] = 1;
            if (j + A[i] <= K) dp1[i + 1][j + A[i]] = 1;
        }
    }

    dp2[N][0] = 1;
    for (int i = N; i > 0; i--) {
        for (int j = 0; j <= K; j++) {
            if (!dp2[i][j]) continue;
            dp2[i - 1][j] = 1;
            if (j + A[i - 1] <= K) dp2[i - 1][j + A[i - 1]] = 1;
        }
        for (int j = 0; j <= K; j++) {
            acc[i][j + 1] = acc[i][j] + dp2[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool flag = false;
        for (int j = 0; j <= K; j++) {
            if (!dp1[i][j]) continue;

            int mi = max(0, K - A[i] - j);
            int ma = max(0, K - j);
            if (acc[i + 1][ma] - acc[i + 1][mi] > 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            ans++;
        } 
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.setf(ios::fixed);
    cout.precision(16);
    solve();
    return 0;
}