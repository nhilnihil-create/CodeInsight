#include "bits/stdc++.h"

using namespace std;

const int INF = 1000000000;
int N, Ma, Mb;
vector<int> a, b, c;

int dp(int curr, int wa, int wb, vector<vector<vector<int>>>& memo) {
    if (wa > 0 && wb > 0 && wb * Ma == wa * Mb) {
        return 0;
    }
    if (curr == N) {
        return INF;
    }

    if (memo[curr][wa][wb] >= 0) {
        return memo[curr][wa][wb];
    }

    int skip = dp(curr + 1, wa, wb, memo);
    int take = dp(curr + 1, wa + a[curr], wb + b[curr], memo) + c[curr];
    int ret = min(skip, take);
    memo[curr][wa][wb] = ret;
    return ret;
}

void Main() {
    cin >> N >> Ma >> Mb;
    a = vector<int>(N, 0);
    b = vector<int>(N, 0);
    c = vector<int>(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<vector<vector<int>>> memo(N, vector<vector<int>>(410, vector<int>(410, -1)));
    int ans = dp(0, 0, 0, memo);
    if (ans == INF) {
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
