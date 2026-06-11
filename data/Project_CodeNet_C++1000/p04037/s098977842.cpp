#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    // sort(a.begin(), a.end(), greater<int>());
    // vector<vector<int>> dp(n);
    // for (int i = 0; i < n; ++i) dp[i].resize(a[i], -1);

    // function<int(int, int)> Dfs = [&](int r, int c) {
        // if (dp[r][c] >= 0) return dp[r][c];
        // dp[r][c] = 0;
        // if (r + 1 < n && c < dp[r + 1].size() && !Dfs(r + 1, c)) dp[r][c] = 1;
        // if (c + 1 < dp[r].size() && !Dfs(r, c + 1)) dp[r][c] = 1;
        // return dp[r][c];
    // };

    // for (int i = 0; i < n; ++i) {
        // for (int j = 0; j < a[i]; ++j) printf("%d ", Dfs(i, j));
        // puts("");
    // }

    set<int> s;
    sort(a.begin(), a.end());
    int shift = 0;
    vector<bool> invert(n);
    for (int i = 1; i < n; ++i) {
        shift++;
        if (a[i] == a[i - 1]) {
            invert[i] = !invert[i - 1];
        } else {
            if (invert[i - 1] && (a[i] - a[i - 1]) % 2 == 1) {
                s.insert(a[i - 1] - (n - 1 - i));
            }
            if (!invert[i - 1] && (a[i] - a[i - 1]) % 2 == 0) {
                s.insert(a[i - 1] + 1 - (n - 1 - i));
            }
        }
    }

    // printf("s : ");
    // for (auto it : s) printf("%d ", it); puts("");
    int cnt = 0;
    for (auto it : s) cnt += it >= 3;
    if (s.count(1) || s.count(2)) puts("First");
    else if (!invert[n - 1] && a[n - 1] % 2 == cnt % 2) puts("First");
    else if (!invert[n - 1] && a[n - 1] % 2 != cnt % 2) puts("Second");
    else if (invert[n - 1] && a[n - 1] % 2 != cnt % 2) puts("First");
    else puts("Second");
}
