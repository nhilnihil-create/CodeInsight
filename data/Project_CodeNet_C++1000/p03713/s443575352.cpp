#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 using ll = long long;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 const ll MOD = 1000000007;
 const ll INFL = (1LL << 60);
 const int INFI = (1 << 30);

 int main() {
   ll H, W, ans = INFL; cin >> H >> W;

   if (H % 3 == 0 || W % 3 == 0) ans = 0;

   else {
     ll h3 = H / 3;
     ll w3 = W / 3;

     ll S1, S2, S3;

     for (ll i = 0; i <= W % 3; i++) {
       S1 = (w3 + i) * H;
       S2 = (W - (w3 + i)) * (H / 2);
       S3 = W * H - S1 - S2;

       ans = min(ans, max(S1, max(S2, S3)) - min(S1, min(S2, S3)));
     }

     for (ll i = 0; i <= H % 3; i++) {
       S1 = (h3 + i) * W;
       S2 = (H - (h3 + i)) * (W / 2);
       S3 = W * H - S1 - S2;

       ans = min(ans, max(S1, max(S2, S3)) - min(S1, min(S2, S3)));
     }

     ans = min(ans, min(H, W));
   }

   cout << ans << endl;
 }
