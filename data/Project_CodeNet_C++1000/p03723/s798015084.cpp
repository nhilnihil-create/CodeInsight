#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;


void solveCase() {
   int n;
   vector <int> v(3), v1(3);
   for(auto &e: v) cin >> e;

   int ans = 0;
   map <vector <int>, bool> m;

   while(true) {
      if(m.find(v) != m.end()) {
         cout << -1 << endl;
         return;
      }
      bool odd = false;
      for(auto e: v) if(e % 2 != 0) odd = true;
      if(odd) break;
      ans++;
      m[v] = true;
      v1[0] = (v[1] + v[2]) / 2;
      v1[1] = (v[0] + v[2]) / 2;
      v1[2] = (v[0] + v[1]) / 2;
      v = v1;
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