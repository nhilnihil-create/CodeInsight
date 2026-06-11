#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   int W, H, N;
   cin >> W >> H >> N;
   int left = 0, right = W, bottom = 0, top = H;

   for(int i=0; i<N; i++) {
      int x, y, a;
      cin >> x >> y >> a;

      if(a == 1) {
         left = max(left, x);
      }
      else if(a == 2) {
         right = min(right, x);
      }
      else if(a == 3) {
         bottom = max(bottom, y);
      }
      else if(a == 4) {
         top = min(top, y);
      }
   }
   if(left >= right || bottom >= top) {
      cout << 0 << endl;
      return 0;
   }
   cout << (right - left) * (top - bottom ) << endl;
}