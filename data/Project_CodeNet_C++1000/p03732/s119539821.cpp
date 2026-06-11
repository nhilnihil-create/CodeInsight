#include "bits/stdc++.h"

using namespace std;

long long dp(long long curr, pair<long long, long long> n_w, long long W, long long w0, const vector<long long>& v, const vector<long long>& w
        , map<pair<long long, pair<long long, long long>>, long long>& memo) {

    auto p = make_pair(curr, n_w);
    if (memo.count(p) > 0) {
        return memo[p];
    }
    long long N = v.size();
    if (curr == N) {
        return 0LL;
    }

    long long ret = dp(curr + 1, n_w, W, w0, v, w, memo);
    pair<long long, long long> next_nw = make_pair(n_w.first + 1, n_w.second + w[curr]);
    if (w0 * next_nw.first + next_nw.second <= W) {
        long long take = v[curr] + dp(curr + 1, next_nw, W, w0, v, w, memo);
        ret = max(ret, take);
    }

    memo.insert(make_pair(p, ret));
    return ret;
}

void Main() {
    long long N, W;
    cin >> N >> W;
    vector<long long> w(N, 0LL), v(N, 0LL);
    for (long long i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }

    long long w0 = w[0];
    for (long long i = 0; i < N; ++i) {
        w[i] -= w0;
    }

    map<pair<long long, pair<long long, long long>>, long long> memo;
    long long ans = dp(0, make_pair(0, 0), W, w0, v, w, memo);
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
