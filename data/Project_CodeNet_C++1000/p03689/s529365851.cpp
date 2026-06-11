#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

void solve(int W, int w, vector<int>& a) {
  if (W % w == 0) {
    return;
  }
  vector<int> s(W + 1, 0);
  for (int i = 1; i < w; i++) {
    s[i] = (W + w - 1) / w;
  }
  for (int i = w; i <= W; i++) {
    s[i] = s[i - w] - 1;
  }
  for (int i = 0; i < W; i++) {
    a[i] = s[i + 1] - s[i];
  }
}

int main() {
  int H, W, h, w;
  cin >> H >> W >> h >> w;
  if (H % h == 0 && W % w == 0) {
    cout << "No" << endl;
    return 0;
  }
  vector<int> ys(H, 0), xs(W, 0);
  solve(H, h, ys);
  solve(W, w, xs);
  cout << "Yes" << endl;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << (ys[i] + xs[j]) << " ";
    }
    cout << endl;
  }
  return 0;
}
