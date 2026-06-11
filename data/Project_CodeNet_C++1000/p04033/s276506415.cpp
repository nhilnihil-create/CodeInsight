#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;
 

void solveCase() {
   int a, b;
   cin >> a >> b;
   if(a > 0) {
      cout << "Positive" << endl;
   } else if(b < 0) {
      if((b - a + 1) % 2)
         cout << "Negative" << endl;
      else cout << "Positive" << endl;
   } else {
      cout << "Zero" << endl;
   }
}
 
int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   
   int testcase = 1;
   // cin >> testcase;
 
   for(int i = 0; i < testcase; i++) {
      solveCase();
   }
 
   return 0;
}