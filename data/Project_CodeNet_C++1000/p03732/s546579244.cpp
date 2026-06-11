#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main() {
    lint n, W;
    cin >> n >> W;

    vector<lint> w(n), v(n);
    for(lint i=0; i<n; i++)  cin >> w[i] >> v[i];

    map<lint, lint> dp;
    dp[0] = 0;
    for(lint i=0; i<n; i++) {
        map<lint, lint> dp_tmp(begin(dp), end(dp));
        for(auto e : dp) {
            lint key, value;
            tie(key, value) = e;
            dp_tmp[key + w[i]] = max(dp_tmp[key + w[i]], dp[key] + v[i]);
        }
        dp = dp_tmp;
    }

    lint ans = 0;
    for(auto e : dp) {
        lint key, value;
        tie(key, value) = e;
        if(key > W)  break;
        ans = max(ans, value);
    }
    cout << ans << endl;
}