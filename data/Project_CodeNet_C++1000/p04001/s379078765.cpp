#include <bits/stdc++.h>
using namespace std;
#define int long long
int res = 0;
string s;
void dfs(int i, int sum, int psum, string &s) {
  int n = s.size();
  int si = s.at(i) - '0';
  if (i == n - 1) {
    res += sum + si + 10 * psum;
    return;
  }
  dfs(i + 1, sum + si + 10 * psum, 0, s);
  dfs(i + 1, sum, 10 * psum + si, s);
}
signed main() {
  cin >> s;
  dfs(0, 0, 0, s);
  cout << res << endl;
}
 