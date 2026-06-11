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

int main() {
  const string color = "RGBY";
  int H, W, d;
  cin >> H >> W >> d;
  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      int py = ((y - x) + 1000 * d) / d % 2;
      int px = ((y + x) + 1000 * d) / d % 2;
      cout << color[py * 2 + px];
    }
    cout << endl;
  }
  return 0;
}
