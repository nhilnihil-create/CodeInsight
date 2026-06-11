#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const ll inf = 1e18;

int main() {
   int n, k;
   cin >> n >> k;
   vector<int> a(n);
   rep(i,n) cin >> a[i];
   ll ans = inf;
   rep(i,1<<n) {
      ll t = 0;
      if (!(i & 1)) continue;
      if (__builtin_popcount(i) != k) continue;
      int high = a[0];
      for (int j = 1; j < n; j++) {
         if (i>>j & 1) {
            high = max(a[j],high+1);
            t += high-a[j];
         }
         else high = max(a[j],high);
      }
      ans = min(ans,t);
   }
   cout << ans << endl;
}