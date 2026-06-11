#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
#define PI 3.1415926535

int main(void)
{
   ll q, h, s, d, n;
   cin >> q >> h >> s >> d >> n;

   //全て4倍
   n *= 4;
   ll DP[9] = {};
   DP[0] = 0;
   DP[1] = q;

   for (int i = 2; i <= 8; i++){
      if (i < 4){
         DP[i] = min(DP[i - 1] + q, DP[i - 2] + h);
         continue;
      }
      if (i < 8)
      {
         DP[i] = min(DP[i - 1] + q, DP[i - 2] + h);
         DP[i] = min(DP[i], DP[i - 4] + s);
         continue;
      }
      DP[i] = min(DP[i - 1] + q, DP[i - 2] + h);
      DP[i] = min(DP[i], DP[i - 4] + s);
      DP[i] = min(DP[i], DP[i - 8] + d);
   }
   ll ans = DP[8] * (n / 8) + DP[n % 8];

   cout << ans << endl;
   return 0;
}
