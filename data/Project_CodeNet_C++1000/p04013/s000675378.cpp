#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    long n, ave, ans = 0;
    cin >> n >> ave;
    vector<long> x(n);
    vector<vector<vector<long>>> dp(n + 1, vector<vector<long>>(n + 1, vector<long>(50 * n + 1, 0)));
    dp.at(0).at(0).at(0) = 1;
    rep(i, n) cin >> x.at(i);
    rep(i, n) rep(j, n) rep(k, 50 * n + 1) {
        dp.at(i + 1).at(j).at(k) += dp.at(i).at(j).at(k);
        if(k + x.at(i) <= 50 * n) dp.at(i + 1).at(j + 1).at(k + x.at(i)) += dp.at(i).at(j).at(k);
    }
    rep(i, n) ans += dp.at(n).at(i + 1).at((i + 1) * ave);
    cout << ans << endl;
}