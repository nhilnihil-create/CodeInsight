#include "bits/stdc++.h"
using ll = long long;
using namespace std;

void solve() {
   int n, m;
   cin >> n >> m;
   vector <string> s(n);
   for(int i = 0; i < n; i++) {
      cin >> s[i];
      s[i] = "#" + s[i] + "#";
   }
   string pad(m + 2, '#');
   cout << pad << endl;
   for(auto str: s)
      cout << str << endl;
   cout << pad << endl;
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
