#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int H, W, h, w;
   cin >> H >> W >> h >> w;
   if (H % h == 0 && W % w == 0) {
      cout << "No\n";
      return 0;
   }
   cout << "Yes\n";
   for (int i = 0; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
         if (i % h == h - 1 && j % w == w - 1) {
            cout << -3750 * (h * w - 1) - 1 << " ";
         } else {
            cout << 3750 << " ";
         }
      }
      cout << "\n";
   }
}
