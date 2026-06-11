#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using vi = vector<i64>;
using vvi = vector<vi>;

int main() {
    string s;
    cin >> s;
    vi dp(s.size() + 1);
    set<int> ss;
    int cnt = 0;
    priority_queue<i64, vi, greater<>> que[26];
    for (int i = s.size() - 1; i >= 0; i--) {
        ss.insert(s[i]);
        que[s[i] - 'a'].push(i + 1);
        dp[i + 1] = cnt;
        if (ss.size() == 26) {
            ss = set<int>();
            cnt++;
        }
    }
    dp[0] = cnt;
    
    string ans = "";
    int cur = 0;
    int target = dp[0];
    
    while (1) {
        for (int i = 0; i < 26; i++) {
            while (que[i].size() && que[i].top() < cur) {
                que[i].pop();
            }
            if (target == 0) {
                if (que[i].empty()) {
                    ans += 'a' + i;
                    cout << ans << endl;
                    return 0;
                }
            } else {
                if (dp[que[i].top()] < target) {
                    ans += 'a' + i;
                    cur = que[i].top();
                    target = dp[cur];
                    que[i].pop();
                    break;
                }
            }
        }
    }
}
