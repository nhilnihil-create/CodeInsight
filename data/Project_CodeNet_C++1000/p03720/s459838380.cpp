#include "bits/stdc++.h"
using ll = long long;
using namespace std;

void solve() {
   int n, m, x, y;
   cin >> n >> m;
   vector <int> ans(n);
   for(int i = 0; i < m; i++) {
      cin >> x >> y;
      ans[x - 1]++;
      ans[y - 1]++;
   }

   for(int i = 0; i < n; i++) {cout << ans[i] << endl;}
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
