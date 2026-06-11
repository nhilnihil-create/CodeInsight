#include<iostream>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;

  char C[H][W];
  rep(i,0,H-1)
    rep(j,0,W-1) cin >> C[i][j];

  rep(i,0,H-1) {
    rep(j,0,1) {
      rep(k,0,W-1) {
        cout << C[i][k];
      }
      cout << endl;
    }
  }

  return 0;
}
