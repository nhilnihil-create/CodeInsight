#include "bits/stdc++.h"
using namespace std;

// #include "debug.h"
// #define debug(...) 42

using ll = long long;

void solve() {
   ll n, k;
   cin >> n >> k;
   vector <pair <int, int>> v(n);
   for(int i = 0; i < n; i++) {
      cin >> v[i].first >> v[i].second;
   }
   sort(v.begin(), v.end());
   ll cur = 0;
   for(int i = 0; i < n; i++) {
      cur += v[i].second;
      if(cur >= k) {
         cout << v[i].first << endl;
         return;
      }
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
