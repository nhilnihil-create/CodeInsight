#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;
using lint = long long int;
long long int INF = 1001001001001001LL;
int inf = 1000000007;
long long int MOD = 1000000007LL;
double PI = 3.1415926535897932;

template<typename T1,typename T2>inline void chmin(T1 &a,const T2 &b){if(a>b) a=b;}
template<typename T1,typename T2>inline void chmax(T1 &a,const T2 &b){if(a<b) a=b;}

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()

/* do your best */

int main() {
  
  string s; cin >> s;
  int n = s.size();
  int w = 26;
  vector<vector<int>> next(n + 1, vector<int>(26, n));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < w; j++) {
      next[i][j] = next[i + 1][j];
      if (s[i] == (char)(j + 'a')) {
        next[i][j] = i;
      }
    }
  }

  vector<int> dp(n + 1, inf);
  dp[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < w; j++) {
      if (next[i][j] == n) {
        dp[i] = 1;
      } else {
        dp[i] = min(dp[i], dp[next[i][j] + 1] + 1);
      }
    }
  }
  /*
  for (int i = 0; i <= n; i++) {
    cerr << dp[i] << " ";
  }
  cerr << endl;
  */

  int cur = 0;
  string ans = "";
  while (cur < n) {
    // cerr << cur << endl;
    if (dp[cur] == 1) {
      for (int j = 0; j < w; j++) {
        if (next[cur][j] == n) {
          ans += (char)(j + 'a');
          break;
        }
      }
      break;
    }

    for (int j = 0; j < w; j++) {
      // cerr << "cur = " << cur << " j = " << j << " " << next[cur][j] + 1 << endl;
      if (dp[cur] == dp[next[cur][j] + 1] + 1) {
        ans += (char)(j + 'a');
        cur = next[cur][j] + 1;
        break;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
