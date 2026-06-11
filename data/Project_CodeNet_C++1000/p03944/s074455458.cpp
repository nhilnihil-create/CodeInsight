#include <bits/stdc++.h>
using namespace std;

int main(){
   int w, h, n; cin>>w>>h>>n;
   int square[w][h];

   // 初期化
   for(int i = 0; i < w; i ++) {
      for (int j = 0; j < h; j ++) {
         square[i][j] = 0;
      }
   }

   for(int i = 0; i < n; i ++) {
      int x, y, a;
      cin >> x >> y >> a;
      switch (a)
      {
      case 1:
         for (int j = 0; j < x; j++) {
            for(int k = 0; k < h; k++) {
               square[j][k] = 1;
            }
         }
         break;
      case 2:
         for (int j = x; j < w; j ++) {
            for(int k = 0; k < h; k ++) {
               square[j][k] = 1;
            }
         }
         break;
      case 3:
         for (int j = 0; j < w; j ++) {
            for(int k = 0; k < y; k ++) {
               square[j][k] = 1;
            }
         }
         break;
      case 4:
         for (int j = 0; j < w; j ++) {
            for(int k = y; k < h; k ++) {
               square[j][k] = 1;
            }
         }
         break;

      default:
         break;
      }
   }
   int ans = 0;
   for(int i = 0; i < w; i ++) {
      for (int j = 0; j < h; j ++) {
         if (square[i][j] == 0) ans++;
      }
   }

   cout << ans << endl;
   return 0;
}
