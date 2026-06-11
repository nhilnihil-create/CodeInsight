#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<int> ans;
  for (int i = 0; i < N; i++) {
    int tmp = A.at(i);
    while (tmp--) ans.push_back(i + 1);
  }
  vector<int> tmp;
  for (int i = 0, b = 0; i < (int) ans.size(); i++) {
    tmp.push_back(ans.at(i));
    if (tmp.size() == W) {
      if (b) reverse(tmp.begin(), tmp.end());
      for (int j = 0; j < W; j++) {
        if (j) cout << " ";
        cout << tmp.at(j);
      }
      cout << "\n";
      tmp.clear();
      b ^= 1;
    }
  }
}