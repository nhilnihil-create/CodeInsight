#include <bits/stdc++.h>

 using namespace std;
 int main() {
   int H, W, i, j;
   string S;
   bool finished = false;

   cin >> H >> W;
   for (i = 1; i <= H; i++) {
     for (j = 1; j <= W; j++) {
       cin >> S;
       if (S == "snuke") {
         cout << (char)(64 + j) << i << endl;
         finished = true;
         break;
       }
     }
     if (finished) break;
   }
 }
