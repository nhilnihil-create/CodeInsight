#include<bits/stdc++.h>
using namespace std;
int main () {
  int H, W;
  cin >> H >> W;
  int amari2 = 0;
  int odd = 0;
  if (H % 2) {
    amari2 += (W / 2);
  }
  if (W % 2) {
    amari2 += (H / 2);
  }
  if ((H % 2) && (W % 2)) {
    odd = 1;
  }
  vector<int>alpha(26, 0);
  for (int i = 0; i < H; i ++) {
    for (int j = 0; j < W; j ++) {
      char c;
      cin >> c;
      alpha[(int)c - (int)'a'] ++;
    }
  }
  for (int i = 0; i < 26; i ++) {
    if (alpha[i] % 2) odd --;
    if (alpha[i] % 4 == 2) amari2 --;
  }
  cout << ((odd < 0 || amari2 < 0) ? "No" : "Yes") << endl;
}