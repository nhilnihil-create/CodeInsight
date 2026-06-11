#include <bitset>
#include <deque>
#include <cassert>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

long long check(vector<int> &a) {
    long long ans = 0;
    const int n = a.size();
    for (int x = 1; x < n; x++) {
        long long dp[x][n-x];
        memset(dp, 0, sizeof dp);
        dp[0][0] = int(a[0] == a[x]);
        for (int i = 1; i < x; i++)
            dp[i][0] = dp[i-1][0] + int(a[i] == a[x]);
        for (int j = 1; j + x < n; j++) {
            for (int i = 0; i < x; i++) {
                dp[i][j] = dp[i][j-1];
                if (i > 0) {
                    dp[i][j] += dp[i-1][j] - dp[i-1][j-1];
                    if (a[i] == a[j+x]) dp[i][j] += dp[i-1][j-1];
                }
            }
        }
        ans += dp[x-1][n-x-1];
    }
    return ans;
}

int solve(long long n, deque<int> &s, deque<int> &t, int a) {
    if (n > 1) {
        if (n % 2 == 1) {
            a = solve(n / 2, s, t, a);
            s.push_back(a);
            t.push_back(a);
            return a + 1;
        } else {
            a = solve(n - 1, s, t, a);
            s.push_front(a);
            t.push_back(a);
            return a + 1;
        }
    } else {
        s.push_back(a);
        t.push_back(a);
        return a + 1;
    }
}

int main() {
    long long n; cin >> n;
    deque<int> s, t;
    solve(n, s, t, 1);
    vector<int> ans;
    ans.insert(ans.end(), s.begin(), s.end());
    ans.insert(ans.end(), t.begin(), t.end());
    // assert (n == check(ans));
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
}
