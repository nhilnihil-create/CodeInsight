#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);++i)
using namespace std;

int main() {
  int H, W; cin >> H >> W;
  string s[H]; rep(i,H) cin >> s[i];
  rep(i, H+2) {
    rep(j, W+2) {
      if (i == 0 || i == H+1 || j == 0 || j == W+1) {
        cout << "#"; 
      } else {
        cout << s[i-1][j-1];
      }
    }
    cout << endl;
  }
}

