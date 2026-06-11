#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1 << 30;
string s;
int nxt[200010][26];
int dp[200010];
int best[200010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> s;

  int n = s.size();
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      int &nx = nxt[i][j];
      if (i == n) nx = n;
      else if (s[i] - 'a' == j) nx = i;
      else nx = nxt[i+1][j];
    }
  }

  dp[n] = 1;
  for (int i = n-1; i >= 0; i--) {
    dp[i] = INF;
    best[i] = -1;
    for (int j = 0; j < 26; j++) {
      int &nx = nxt[i][j];
      if (nx >= n) {
        if (dp[i] > 1) {
          dp[i] = 1;
          best[i] = j;
        }
      } else if (chmin(dp[i], dp[nxt[i][j]+1]+1)) {
        best[i] = j;
      }
    }
  }

  int cur = 0;
  while (cur < n) {
    cout << char(best[cur]+'a');
    cur = nxt[cur][best[cur]]+1;
  }
  cout << endl;

  return 0;
}