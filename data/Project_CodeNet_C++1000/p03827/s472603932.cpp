#include "bits/stdc++.h"
using ll = long long;
using namespace std;

void solve() {
   int n;
   cin >> n;
   string s;
   cin >> s;
   int x = 0, ans = 0;
   for(int i = 0; i < n; i++) {
      x += s[i] == 'I';
      x -= s[i] == 'D';
      ans = max(ans, x);
   }
   cout << ans << endl;
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
