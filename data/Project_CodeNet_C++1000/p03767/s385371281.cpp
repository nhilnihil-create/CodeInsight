#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;


void solveCase() {
   int n;
   cin >> n;
   vector <int> v(3 * n);

   for(int i = 0; i < 3 * n; i++) {
      cin >> v[i];
   }

   sort(v.begin(), v.end());
   deque <int> d(v.begin(), v.end());
   ll ans = 0;
   while(!d.empty()) {
      d.pop_back();
      d.pop_front();
      ans += d.back();
      d.pop_back();
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