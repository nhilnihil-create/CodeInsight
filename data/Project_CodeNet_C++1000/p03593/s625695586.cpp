#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W; cin >> H >> W;
  vector<string> A(H);
  for (int i = 0; i < H; i++) cin >> A.at(i);
  map<char, int> M;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (M.count(A.at(i).at(j))) M[A.at(i).at(j)]++;
      else M[A.at(i).at(j)] = 1;
    }
  }
  int cnt_odd = 0, cnt2 = 0;
  for (auto p : M) {
    if (p.second % 2 == 1) cnt_odd++;
    if (p.second % 4 == 2) cnt2++;
  }
  bool can = false;
  if (H % 2 == 0 && W % 2 == 0) {
    if (cnt_odd == 0 && cnt2 == 0) can = true;
  }
  else if (H % 2 == 1 && W % 2 == 1) {
    if (cnt_odd == 1 && cnt2 <= H/2 + W/2) can = true;
  }
  else {
    if (H % 2 == 1) {
      if (cnt_odd == 0 && cnt2 <= W / 2) can = true;
    }
    else {
      if (cnt_odd == 0 && cnt2 <= H / 2) can = true;
    }
  }
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}
