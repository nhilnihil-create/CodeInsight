#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)

string divide[4] = {"dream", "dreamer", "erase", "eraser"};
bool dp[100001];
// DP

int main() {
    string S;
    cin >> S;
    dp[0] = 1;
    rep(i, S.size()) {
        if (!dp[i]) continue;
        for (string s : divide) {
            if (S.substr(i, s.size()) == s) dp[i + s.size()] = 1;
        }
    }
    if (dp[S.size()]) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}