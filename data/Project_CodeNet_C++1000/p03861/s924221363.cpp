#include "bits/stdc++.h"
using ll = long long;
using namespace std;

ll f(ll n, ll x) {
   return n / x;
}

void solve() {
   ll a, b, x;
   cin >> a >> b >> x;
   ll ans = 0;
   if (a == 0) ans = 1, a++;
   ans += f(b, x) - f(a - 1, x);
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
