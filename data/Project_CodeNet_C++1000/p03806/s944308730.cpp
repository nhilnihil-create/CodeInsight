#include <iostream>
#include <vector>
#include <algorithm>
// #include <string>
// #include <map>
// #include <set>
// #include <cmath>

#define INF 10000

using namespace std;
// typedef unsigned long long ull;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    for (const auto i : v) {
        os << i << " ";
    }
    os << "]";
    return os;
}

int main(int argc, char const *argv[]) {
    int N, Ma, Mb;
    cin >> N >> Ma >> Mb;

    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    int a_max = *max_element(a.begin(), a.end());
    int b_max = *max_element(b.begin(), b.end());
    // cout << a_max << " " << b_max << endl;

    vector<vector<vector<int>>> dp(N+1);
    for (int i = 0; i <= N; ++i) {
        dp[i].resize(a_max * N + 1);
        for (int j = 0; j <= a_max * N; ++j) {
            dp[i][j].resize(b_max * N + 1, INF);
        }
    }

    dp[0][0][0] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= a_max * N; ++j) {
            for (int k = 0; k <= b_max * N; ++k) {
                if (j >= a[i] && k >= b[i]) {
                    dp[i+1][j][k] = min(dp[i][j][k], dp[i][j-a[i]][k-b[i]] + c[i]);
                } else {
                    dp[i+1][j][k] = dp[i][j][k];
                }
            }
        }
    }

    int r = 1;
    int ans = INF;
    while (true) {
        int ma = Ma * r;
        int mb = Mb * r;
        if (ma > a_max * N || mb > b_max * N) {
            break;
        }
        ans = min(ans, dp[N][ma][mb]);
        r += 1;
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
