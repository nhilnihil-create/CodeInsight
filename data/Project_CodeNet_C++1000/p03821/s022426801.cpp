#include "bits/stdc++.h"

using ll = long long;
using namespace std;

void solve() {
   int n;
   cin >> n;
   vector <ll> a(n);
   vector <int> b(n);
   for(int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
   }

   ll ans = 0;
   for(int i = n - 1; i >= 0; i--) {
      a[i] += ans;
      ans += (b[i] - (a[i] % b[i])) % b[i];
   }
   cout << ans << endl;
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