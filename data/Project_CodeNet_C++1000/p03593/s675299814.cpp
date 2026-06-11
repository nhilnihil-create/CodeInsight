#include<bits/stdc++.h>
using namespace std;

bool solve() {
  int H, W; cin >> H >> W;
  int g1 = H & W & 1;
  int g2 = H % 2 * W / 2 + W % 2 * H / 2;
  vector<int> cnt(26);
  for (int i = 0; i < H*W; i++) {
    char c; cin >> c;
    ++cnt[c-'a'] &= 3;
  }
  int c1 = 0, c2 = 0;
  for (int i = 0; i < 26; i++) {
    c2 += cnt[i] & 2;
    c1 += cnt[i] & 1;
  }
  if (c1 > g1 || c2 / 2 > g2) return false;
  return true;
  
}

int main() {
  if (solve()) cout << "Yes" << endl;
  else cout << "No" << endl;
}
