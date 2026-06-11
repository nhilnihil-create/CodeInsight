#include "bits/stdc++.h"
 
using ll = long long;
using namespace std;


void solveCase() {
   int n;
   cin >> n;
   vector <int> v(n);
   for(auto &e: v) {
      cin >> e;
   }
   int evn = 0;
   int odd = 0;
   
   for(auto &e: v) {
      if(e % 2 == 0) evn++;
      else odd++;
   }

   if(evn % 2 == 1) {
      if(odd % 2 == 0) {
         cout << "YES" << endl;
      } else {
         cout << "NO" << endl;
      }
   } else {
      if(odd % 2 == 0) {
         cout << "YES" << endl;
      } else {
         cout << "NO" << endl;
      }
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