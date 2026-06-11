#include "bits/stdc++.h"
using namespace std;
using ll = long long;
// #include "debug.h"
#define debug(...) 42

ll f(int a, int b) {
   return max((ll)to_string(a).length(), (ll)to_string(b).length());
}

void solve() {
   ll n;
   cin >> n;
   ll ans = LONG_MAX;
   for(ll i = 1; i * i <= n; i++) {
      if(n % i == 0) {
         ll a = i;
         ll b = n / i;
         ans = min(ans, f(a, b));
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
      solve();
   }
   return 0;
}
