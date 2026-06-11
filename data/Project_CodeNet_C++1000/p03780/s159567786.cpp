#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

bool dp[5010][5010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    Vl A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int left = -1, right = N;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for (int i = 0; i < N; i++) {
            for (int x = 0; x <= K; x++) {
                ll xx = min(x + A[i], (ll)K);
                dp[i + 1][x] |= dp[i][x];
                if (i != mid)
                    dp[i + 1][xx] |= dp[i][x];
            }
        }
        bool ok = false;
        for (int x = max(K - A[mid], 0ll); x < K; x++) {
            if (dp[N][x]) {
                ok = true;
                break;
            }
        }
        if (ok) {
            right = mid;
        }
        else {
            left = mid;
        }
    }

    cout << left + 1 << endl;

    return 0;
}