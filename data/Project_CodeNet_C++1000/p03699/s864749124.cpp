#include "bits/stdc++.h"

using namespace std;

int dp(int curr, int accum, const vector<int>& s, vector<vector<int>>& memo) {
    if (curr == s.size()) {
        return accum % 10 == 0 ? 0 : accum;
    }
    if (memo[curr][accum] >= 0) {
        return memo[curr][accum];
    }
    int take = dp(curr + 1, accum + s[curr], s, memo);
    int skip = dp(curr + 1, accum, s, memo);
    int ret = max(take, skip);
    memo[curr][accum] = ret;
    return ret;
}

void Main() {
    int N;
    cin >> N;
    vector<int> s(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
    }

    vector<vector<int>> memo(110, vector<int>(10010, -1));
    int ans = dp(0, 0, s, memo);
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
