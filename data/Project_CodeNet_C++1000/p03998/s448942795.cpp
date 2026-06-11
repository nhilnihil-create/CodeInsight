#include <bits/stdc++.h>
using namespace std;

int main() {
  string S[3];
  for (int i = 0; i < 3; ++i) cin >> S[i];
  
  vector<vector<int>> cards(3);
  for (int i = 0; i < 3; ++i) {
    for (auto &c : S[i]) {
      int n = -1;
      if (c == 'a') n = 0;
      if (c == 'b') n = 1;
      if (c == 'c') n = 2;
      cards[i].emplace_back(n);
    }
  }
  
  for (int i = 0; i < 3; ++i) reverse(cards[i].begin(), cards[i].end());
  int now = 0;
  while (1) {
    if (cards[now].empty()) break;
    int tmp = cards[now].back();
    cards[now].pop_back();
    now = tmp;
  }

  char ans[3] = {'A', 'B', 'C'};
  cout << ans[now] << endl;
}
