#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int INF = (int)1e9 + 7;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<vector<int>> calc_next(const string &s) {
    int n = s.size();
    vector<vector<int>> nxt(n + 1, vector<int>(26, n));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) nxt[i][j] = nxt[i + 1][j];
        nxt[i][s[i] - 'a'] = i;
    }
    return nxt;
}

int main() {
    string s; cin >> s;
    int n = s.length();
    auto nxt = calc_next(s);
    vector<int> dp(n + 2, INF);
    vector<pair<char, int>> his(n, {'?', n});
    dp[n + 1] = 0;
    for (int i = n - 1; i >= 0; i--) for (int j = 0; j < 26; j++) {
        if (chmin(dp[i], dp[nxt[i][j] + 1] + 1)) {
            his[i] = {'a' + j, nxt[i][j] + 1};
        }
    }
    string res;
    int idx = 0;
    while (idx < n) {
        auto p = his[idx];
        res += p.first;
        idx = p.second;
    }
    cout << res << endl;
    return 0;
}
