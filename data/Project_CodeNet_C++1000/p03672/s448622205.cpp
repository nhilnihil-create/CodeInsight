#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
   string s;
   cin >> s;
   int a = s.size();

   for(int i=0; i<a; i++) {
      s.pop_back();
      if(s.size() % 2 == 0) {
         int A = s.size() / 2;
         string Q = s.substr(0, A);
         string E = s.substr(A, A);
         if(Q == E) {
            cout << s.size() << endl;
            return 0;
         }
      }
   }
}