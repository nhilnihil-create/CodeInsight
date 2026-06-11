#include <cstdint>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

namespace {
int64_t H, W;
}

int64_t Horizontal() {
  int64_t h1 = H / 3;
  int64_t h2 = (H - h1) / 2;
  int64_t h3 = H - h1 - h2;
  int64_t area1 = h1 * W;
  int64_t area2 = h2 * W;
  int64_t area3 = h3 * W;
  
  return max(area1, max(area2, area3)) - min(area1, min(area2, area3));
}

int64_t Vertical() {
  int64_t w1 = W / 3;
  int64_t w2 = (W - w1) / 2;
  int64_t w3 = W - w1 - w2;
  int64_t area1 = w1 * H;
  int64_t area2 = w2 * H;
  int64_t area3 = w3 * H;
  
  return max(area1, max(area2, area3)) - min(area1, min(area2, area3));
}

int64_t HorizontalMain() {
  int64_t diff = numeric_limits<int64_t>::max();
  
  int64_t half = W / 2;
  for (int64_t h = 1; h < H; ++h) {
    int64_t area1 = h * W;
    int64_t area2 = (H - h) * half;
    int64_t area3 = (H - h) * (W - half);

    diff = min(diff, max(area1, max(area2, area3)) - min(area1, min(area2, area3)));
  }
  return diff;
}

int64_t VerticalMain() {
  int64_t diff = numeric_limits<int64_t>::max();
  
  int64_t half = H / 2;
  for (int64_t w = 1; w < W; ++w) {
    int64_t area1 = w * H;
    int64_t area2 = (W - w) * half;
    int64_t area3 = (W - w) * (H - half);

    diff = min(diff, max(area1, max(area2, area3)) - min(area1, min(area2, area3)));
  }
  return diff;
}

int main() {
  cin >> H >> W;

  if (H % 3 == 0) { cout << 0 << endl; return 0; }
  if (W % 3 == 0) { cout << 0 << endl; return 0; }

  int64_t diff = numeric_limits<int64_t>::max();
  diff = min(diff, Horizontal());
  diff = min(diff, Vertical());
  diff = min(diff, HorizontalMain());
  diff = min(diff, VerticalMain());
  
  cout << diff << endl;
  
  return 0;
}
