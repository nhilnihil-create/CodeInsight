#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
   int ans = 0;
   int next = 1;
   cin >> n;
   vector<int> a(n);
   for (int i=0; i<n; i++) {
       cin >> a.at(i);
   }
   
   for (int i=0; i<n; i++) {
      ans++;
      if (a.at(next-1) == 2) {
          break;
      }
      next = a.at(next-1);
      if (i == n-1) {
          ans = -1;
      }
   }
   
   cout << ans << endl;

}