#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;


void solveCase() {
   int n, c, k;
   cin >> n >> c >> k;
   vector <int> t(n);
   for(int i = 0; i < n; i++) {
      cin >> t[i];
   }
   sort(t.begin(), t.end());

   int last_bus_time = t[0];
   int bus_count = 1;
   int pass = 0;
   for(int i = 0; i < n; i++) {
      if(t[i] - last_bus_time > k || pass == c) {
         last_bus_time = t[i];
         bus_count ++;
         pass = 1;
      } else {
         pass++;
      }
   }
   cout << bus_count << endl;
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