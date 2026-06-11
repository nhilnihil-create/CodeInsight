#include <bits/stdc++.h>

 using namespace std;

 int main() {
   int X;
   cin >> X;

   for (int i = 1;; i++) {
     if (X <= i * (i + 1) / 2) {
       cout << i << endl;
       break;
     }
   }
}
