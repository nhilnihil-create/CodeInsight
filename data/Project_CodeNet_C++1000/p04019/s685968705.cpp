#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;
 

void solveCase() {
   map <char, int> m = {{'N', 1}, {'S', -1}, {'E', 100}, {'W', -100}};
   string s;
   cin >> s;
   set <char> t(s.begin(), s.end());
   int ans = 0;
   for(auto &c: t)  {
      ans += m[c];
   }
   cout << ((ans == 0)?"Yes": "No") << endl;
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