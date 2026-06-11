#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int div_round_down(int a, int b) {
  if (b < 0) return div_round_down(-a, -b);
  if (a >= 0) return a / b;
  return -(((-a) + b - 1) / b);
}

int main() {
  int h, w, d;
  scanf("%d %d %d", &h, &w, &d);
  const char colors[] = "RYGB";
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      int color;
      if (d % 2 == 1) color = (x + y) % 2;
      else {
        int a = ((x + y) / d) % 2;
        int b = (div_round_down(x - y, d) % 2 + 2) % 2;
        color = 2 * a + b;
      }
      printf("%c", colors[color]);
    }
    printf("\n");
  }
  return 0;
}
