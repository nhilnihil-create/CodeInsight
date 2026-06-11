#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
  int H, W; cin >> H >> W;
  vector<vector<string>> S(H,vector<string>(W));
  rep(i, 0, H) rep(j, 0, W) cin >> S[i][j];
  rep(i, 0, H) rep(j, 0, W) {
    if(S[i][j] == "snuke") {
      cout << char('A' + j)  << (i + 1) << endl;
    }
  }
  return 0;
}
