#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;
 

void solveCase() {

   vector <int> v(3);
   for(auto &e: v) {
      cin >> e;
   }
   sort(v.begin(), v.end());

   ll ans = LONG_MAX;
   do {
      if(v[0] % 2 == 0) {
         ans = min(ans, 0LL);
      } else {
         ans = min(ans, v[1] * 1LL * v[2]);
      }
   } while(next_permutation(v.begin(), v.end()));
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