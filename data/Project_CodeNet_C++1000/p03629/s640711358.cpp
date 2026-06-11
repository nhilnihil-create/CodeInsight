#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;
  int n = s.length();

  vector<vector<int>> next(26, vector<int>(n + 1, n));
  for (int c = 0; c < 26; c++) {
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == c + 'a') {
        next[c][i] = i;
      } else {
        next[c][i] = next[c][i + 1];
      }
    }
  }

  vector<int> jump(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      jump[i] = max(jump[i], next[j][i]);
    }
  }
  vector<int> dp(n + 2);
  for (int i = n - 1; i >= 0; i--) {
    if (jump[i] < n) {
      dp[i] = dp[jump[i] + 1] + 1;
    }
  }
  
  int L = dp[0], pos = 0;
  vector<int> ans(L);
  for (int i = 0; i < L; i++) {
    for (int j = 0; j < 26; j++) {
      if (dp[next[j][pos] + 1] < L - i) {
        ans[i] = j;
        pos = next[j][pos] + 1;
        break;
      }
    }
  }
  for (auto i : ans) {
    cout << char(i + 'a');
  }

  vector<bool> visit(26);
  for (int i = pos; i < n; i++) {
    visit[s[i] - 'a'] = true;
  }
  for (int i = 0; i < 26; i++) {
    if (!visit[i]) {
      cout << char(i + 'a') << '\n';
      break;
    }
  }

  return 0;
}
