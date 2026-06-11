#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <deque>

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 234567;
char s[MAXN];
int dp[87], cur[87];
int pre[MAXN];

int main() {
    while (~scanf("%s", s)) {
          int n = strlen(s);
          for (int i = 0; i < 26; i++) {
              dp[i] = 1;
              pre[i + n] = n + 26 + i;
              s[i + n] = i + 'a';
              cur[i] = i + n;
          }
          for (int i = n - 1; i >= 0; i--) {
              int idx = 0;
              for (int i = 1; i < 26; i++) {
                  if (dp[i] < dp[idx]) idx = i;
              }
              pre[i] = cur[idx];
              cur[s[i] - 'a'] = i;
              dp[s[i] - 'a'] = dp[idx] + 1;
          }
          int ans_i = 0;
          for (int i = 1; i < 26; i++) {
              if (dp[i] < dp[ans_i]) ans_i = i;
          }
          int ans_cur = cur[ans_i];
          while (ans_cur < n + 26) {
                printf("%c", s[ans_cur]);
                ans_cur = pre[ans_cur];
          }
          puts("");
    }
    return 0;
}
