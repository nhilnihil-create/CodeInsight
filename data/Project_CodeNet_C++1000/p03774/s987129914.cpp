#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> s(N);
  rep(i,0,N-1) cin >> s[i].first >> s[i].second;

  vector<pair<int, int>> c(M);
  rep(i,0,M-1) cin >> c[i].first >> c[i].second;

  vector<int> answers(N);
  rep(i,0,N-1) {
    pair<int,int> stu = s[i];
    int x1 = stu.first, y1 = stu.second;
    int d = 1001001001;
    int ans;
    rep(j,0,M-1) {
      pair<int,int> cp = c[j];
      int x2 = cp.first, y2 = cp.second;
      int tmp_d = abs(x1 - x2) + abs(y1 - y2);
      if (tmp_d < d) {
        d = tmp_d;
        ans = j + 1;
      }
    }
    answers[i] = ans;
  }

  for (int ans : answers) cout << ans << endl;
  return 0;
}
