#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int n;
   ll a, b, c, d;
   cin >> n >> a >> b >> c >> d;
   for (int i = 0; i < n; ++i) {
      ll l = a + c * i - d * (n - 1 - i);
      ll r = a + d * i - c * (n - 1 - i);
      if (l <= b && b <= r) {
         puts("YES");
         return 0;
      }
   }
   puts("NO");
   return 0;
}
