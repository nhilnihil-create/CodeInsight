#include "bits/stdc++.h"

using ll = long long;
using namespace std;

void solve() {
   int p;
   int n;
   cin >> n >> p;

   vector <int> v(n);
   int even = 0;
   int odd = 0;
   for(int i = 0; i < n; i++) {
      cin >> v[i];
      v[i] %= 2;
      even += v[i] == 0;
      odd += v[i] == 1;
   }

   if(odd == 0) {
      if(p == 1) {
         cout << 0 << endl;
      } else {
         cout << (1LL << n) << endl;
      }
   } else {
      cout << (1LL << (n - 1)) << endl;
   }
}


int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   
   int testcase = 1;
   // cin >> testcase;
 
   for(int i = 0; i < testcase; i++) {
      solve();
   }
 
   return 0;
}
