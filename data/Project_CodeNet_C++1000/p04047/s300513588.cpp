#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;
 

void solveCase() {
   int n;
   cin >> n;
   vector<int> l(2 * n);
   for(int i = 0; i < 2 * n; i++) {
      cin >> l[i];
   }
   sort(l.rbegin(), l.rend());
   int ans = 0;
   for(int i = 0; i < 2 * n; i += 2) {
      ans += min(l[i], l[i + 1]);
   }
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