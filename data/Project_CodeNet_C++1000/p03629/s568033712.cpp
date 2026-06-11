#include <algorithm>
#include <bitset>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/

// https://suikaba.hatenablog.com/entry/2017/08/20/232530
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  string a; cin >> a;
  int sz = a.size();
  // next[i][char] = a の i 文字目以降 (i 文字目を含む)で
  //                 最初に文字 char が現れる index (0-based)
  vector<vector<int> > next(sz, vector<int>(26, sz));
  next[sz - 1][a[sz - 1] - 'a'] = sz - 1;
  for (int i = sz - 2; i >= 0; --i) {
    REP(j, 26) next[i][j] = next[i + 1][j];
    next[i][a[i] - 'a'] = i;
  }
  // dp[i] = a の i 文字目以降 (i 文字目を含む) で
  //         部分列とならない最短の文字列長 (0-based)
  // dp[0] が求める解の長さ
  vector<int> dp(sz + 1, sz + 1);
  dp[sz] = 1;
  for (int i = sz - 1; i >= 0; --i) REP(j, 26) {
    if (next[i][j] == sz) dp[i] = 1;
    else dp[i] = min(dp[i], dp[next[i][j] + 1] + 1); // A to Z
  }
  string ans = "";
  int now_pos = 0; // 現在見ている a の index
  REP(i, dp[0]) {
    // 次に文字 c が現れる index で丁度 dp の値が変わっているか
    REP(j, 26) {
      if (i == dp[0] - 1) {
        if (next[now_pos][j] == sz) {
          ans += (char)('a' + j);
          break;
        }
      } else if (dp[next[now_pos][j] + 1] == dp[0] - i - 1) {
        now_pos = next[now_pos][j] + 1;
        ans += (char)('a' + j);
        break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
