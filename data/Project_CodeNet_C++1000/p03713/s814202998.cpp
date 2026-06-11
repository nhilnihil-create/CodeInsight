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

   ll S1, S2, S3;

   rep(i, 1, H) {
     S1 = W * i;
     S2 = W / 2 * (H - i);
     S3 = (W - W / 2) * (H - i);

     ans = min(ans, max(S1, max(S2, S3)) - min(S1, min(S2, S3)));

     S2 = (H - i) / 2 * W;
     S3 = H * W - S1 - S2;
     ans = min(ans, max(S1, max(S2, S3)) - min(S1, min(S2, S3)));
   }

   rep(i, 1, W) {
     S1 = H * i;
     S2 = H / 2 * (W - i);
     S3 = (H - H / 2) * (W - i);

     ans = min(ans, max(S1, max(S2, S3)) - min(S1, min(S2, S3)));

     S2 = (W - i) / 2 * H;
     S3 = H * W - S1 - S2;
     ans = min(ans, max(S1, max(S2, S3)) - min(S1, min(S2, S3)));
   }

   cout << ans << endl;
 }
