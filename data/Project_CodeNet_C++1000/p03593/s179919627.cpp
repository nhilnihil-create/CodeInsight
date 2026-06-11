#include <vector>
#include <iostream>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
int a[26];

int main() {
  int H, W; cin >> H >> W;
  rep(y, H) rep(x, W) {
    char c; cin >> c;
    a[c-'a']++;
  }

  int A = (H/2) * (W/2) * 4, B, C = (H%2)*(W%2); B = (H*W) - A - C; A /= 4, B /= 2;
  rep(i, 26) {
    while(a[i] >= 4 && A >= 1) {A--, a[i] -= 4;}
  }
  rep(i, 26) {
    while(a[i] >= 2 && B >= 1) {B--, a[i] -= 2;}
  }
  rep(i, 26) {
    while(a[i] >= 1 && C >= 1) {C--, a[i] -= 1;}
  }

  if(A+B+C >= 1) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
