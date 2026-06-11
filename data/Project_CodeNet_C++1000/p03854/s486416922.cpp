#include <bits/stdc++.h>
using namespace std;

int main(){
   string s;cin >> s;
   string dream   = "dream";
   string dreamer = "dreamer";
   string erase   = "erase";
   string eraser  = "eraser";


   reverse(s.begin(), s.end());
   reverse(dream.begin(), dream.end());
   reverse(dreamer.begin(), dreamer.end());
   reverse(erase.begin(), erase.end());
   reverse(eraser.begin(), eraser.end());

   string can = "YES";

   // for(int i = 0; i < s.end()+1; i++) {
   //    if()
   // }
   while (s.size() != 0) {
      string tmp = s;
      if (s.substr(0, 5) == dream || s.substr(0, 5) == erase) {
         s = s.substr(5);
      } else if (s.substr(0, 6) == eraser) {
         s = s.substr(6);
      } else if (s.substr(0, 7) == dreamer) {
         s = s.substr(7);
      }

      // ちぎれなかった場合
      if (tmp == s) {
         can = "NO";
         break;
      }

      // if (s.size() <= 7 && s.size() != 0 &&
      //    (s != dream && s != dreamer && s != erase && s != eraser)) {
      //       can = "NO";
      //       break;
      // }
   }

   cout << can << endl;
   return 0;
}
