#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int H, W, h, w; cin >> H >> W >> h >> w;
  if (H%h==0&&W%w==0) {cout << "No" << endl; return 0;}
  int pos = 1000;
  int neg = -1 * (pos*(h*w-1)+1);
  int result[H][W];
  rep(i,H) rep(j,W) {
    result[i][j] = ((i+1)%h==0&&(j+1)%w==0) ? neg : pos;
  }

  cout << "Yes" << endl;
  rep(i,H) {
    rep(j,W) cout << result[i][j] << " ";
    cout << endl;
  }
  return 0;
}