#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

typedef long long ll;
typedef long double ld;

const ll SIZE = 2 * 1e5 + 10, MOD = 1e9 + 7, INF = 1e9;

ll dp[SIZE], lst[SIZE][26];

int main() {
    fastInp;

    string s;
    cin >> s;

    ll n = s.size();
    for (int i = 0; i < 26; i++) {
        lst[n][i] = INF;
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            lst[i][j] = lst[i + 1][j];
        }
        lst[i][s[i] - 'a'] = i;
    }

    for (int i = n - 1; i >= 0; i--) {
        ll mx = -1;
        for (int j = 0; j < 26; j++) {
            mx = max(mx, lst[i + 1][j]);
        }
        if (mx == INF) {
            dp[i] = 1;
        }
        else {
            dp[i] = dp[mx] + 1;
        }
    }

    string ans;
    ll ind = -1;
    while (ind != INF) {
        ll mn = INF;
        for (int j = 0; j < 26; j++) {
            if (lst[ind + 1][j] == INF) {
                mn = 0;
            }
            else {
                mn = min(mn, dp[lst[ind + 1][j]]);
            }
        }
        for (int j = 0; j < 26; j++) {
            if (lst[ind + 1][j] == INF) {
                ans.push_back('a' + j);
                ind = INF;
                break;
            }
            if (dp[lst[ind + 1][j]] == mn) {
                ind = lst[ind + 1][j];
                ans.push_back('a' + j);
                break;
            }
        }
    }

    cout << ans;
    return 0;
}
