#include"bits/stdc++.h"
using namespace std;

long long N, K;
vector<long long> a;

bool isNeed(pair<long long, int> x) {
    vector<vector<bool>> dp(N + 1, vector<bool>(K + 1, false));
    //dp[i][j] = i枚目まで見たとき、和がjとなる集合が存在するか
    for (int i = 0; i <= N; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= N; i++) {
        if (i == x.second + 1) {
            //スキップ
            for (int j = 0; j <= K; j++) {
                dp[i][j] = dp[i - 1][j];
            }
            continue;
        }

        for (int j = 0; j <= K; j++) {
            if (j - a[i - 1] < 0) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - a[i - 1]]);
        }
    }

    for (int j = K - 1; j >= K - x.first; j--) {
        if (dp[N][j]) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> N >> K;
    a.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<pair<long long, int>> value_index(N);
    for (int i = 0; i < N; i++) {
        value_index[i].first = a[i];
        value_index[i].second = i;
    }
    sort(value_index.begin(), value_index.end());

    int need = N, not_need = -1;
    while (need - not_need != 1) {
        int mid = (need + not_need) / 2;
        (isNeed(value_index[mid]) ? need = mid : not_need = mid);
    }

    cout << need << endl;
}