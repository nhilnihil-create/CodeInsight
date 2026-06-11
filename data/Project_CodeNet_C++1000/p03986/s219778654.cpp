#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;
 

void solveCase() {
   string s;
   cin >> s;

   int n = s.length();
   stack <char> stk;
   for(int i = 0; i < n; i++) {
      if(stk.empty()) {
         stk.push(s[i]);
      } else if(s[i] == 'S') {
         stk.push(s[i]);
      } else {
         if(stk.top() == 'S') {
            stk.pop();
         } else{
            stk.push(s[i]);
         }
      }
   }
   cout << stk.size() << endl;
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