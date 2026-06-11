#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;


void solveCase() {
   int n, a, b;
   cin >> n >> a >> b;
   if(a > b) {
      cout << 0 << endl;
      return;
   }
   if(n == 1) {
      cout << 1 * (a == b) << endl;
      return;
   }

   ll ans = (n - 2) * 1LL * (b - a) + 1;
   cout << ans << endl;
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