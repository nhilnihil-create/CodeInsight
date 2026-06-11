#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> c(H);
  for (int i = 0; i < H; i++) cin >> c[i];

  vector<string> ans(2 * H);
  for (int i = 0; i < H; i++) {
    ans[2*i] = c[i];
    ans[2*i+1] = c[i];
  }
  for (int i = 0;  i < 2 * H; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}
