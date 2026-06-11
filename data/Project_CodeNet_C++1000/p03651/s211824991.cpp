#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;


void solveCase() {
   int n, k;
   cin >> n >> k;
   vector <int> v(n);
   for(int i = 0; i < n; i++) {
      cin >> v[i];
   }
   int g = 0;
   for(int i = 0; i < n; i++) {
      g = std::gcd(g, v[i]);
   }

   if(k % g == 0 && k <= *max_element(v.begin(), v.end())) {
      cout << "POSSIBLE" << endl;
   } else {
      cout << "IMPOSSIBLE" << endl;
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

