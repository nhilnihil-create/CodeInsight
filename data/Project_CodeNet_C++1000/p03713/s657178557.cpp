#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   ll H, W; cin >> H >> W;

   ll ans = 1e18;
   for (int k = 0; k < 2; k++) {
      for (int i = 1; i < H; i++) {
         ll a = i*W; // 一番上のやつの面積
         // 縦と横に3分割したとき 
         ll b = (W/2) * (H-i);
         ll c = ((W+1)/2) * (H-i);
         ans = min(ans, abs(max({a, b, c}) - min({a, b, c})));
         // 縦に3分割したとき 
         b = ((H-i)/2) * W;
         c = ((H-i+1)/2) * W;
         ans = min(ans, abs(max({a, b, c}) - min({a, b, c})));
      }
      swap(H, W);
   }

   cout << ans << endl;

   return 0;
}
