#include <bits/stdc++.h>
using namespace std;

int dps(vector<vector<int>> &winners, int N, int i) {
    if (winners[i].size() == 0) {
    return 0;
  }
  vector<int> depth;
  for (auto v : winners[i]) {
    depth.push_back(dps(winners, N, v));
  }
  sort(depth.begin(), depth.end(), greater<int>());
  int j = 1;
  for (auto &item : depth) {
    item += j;
    j++;
  }
  return *max_element(depth.begin(), depth.end());
}

int main() {
  int N;
  cin >> N;
  vector<vector<int>> winners(N + 1);
  for (int i = 2; i < N + 1; ++i) {
    int winner;
    cin >> winner;
    winners[winner].push_back(i);
  }
  cout << dps(winners, N, 1) << endl;
}
