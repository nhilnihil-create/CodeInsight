#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;
 

void solveCase() {
   int n;
   string s, t;
   cin >> n >> s >> t;
   if(s.length() + t.length() <= n) {
      cout << s.length() + t.length() << endl;
      return;
   }

   // [0....l1-1]
   int l1 = s.length();
   int l2 = t.length();
   int ans = l1 + l2;
   for(int l = l1 + l2 - 1; l >= max(l1, l2); l--) {
      string tmp = s.substr(0, l - l2);
      tmp = tmp + t;
      if(tmp.substr(0, l1) == s) {
         ans = min(ans, l);
      }
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