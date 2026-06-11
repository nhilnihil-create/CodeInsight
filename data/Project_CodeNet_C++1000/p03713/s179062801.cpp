#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
static const int INF = 2000000000;

ll maxs (ll x, ll y){
  if (x > y) return x;
  else return y;
}

ll mins (ll x, ll y){
  if (x > y) return y;
  else return x;
}

int main(){
  ll H, W;
  cin >> H >> W;
  if (H % 3 && W % 3){
    ll ans = INF;
    for (ll h = 1; h < H; h++) {
      ll s1 = h * W;
      ll w = W/2;
      ll s2 = (H - h) * w;
      ll s3 = (H-h)*(W-w);
      ll s_max = maxs(s1, maxs(s2, s3));
      ll s_min = mins(s1, mins(s2, s3));
      ll sa = abs(s_max - s_min);
      ans = mins(ans, sa);
    }
    for (ll h = 1; h < H; h++) {
      ll s1 = h * W;
      ll s2, s3;
      if ((H-h) % 2 == 0) {  
        s2 = ((H - h) / 2) * W;
        s3 = s2;
      } else {
        s2 = ((H - h) / 2) * W;
        s3 = ((H - h) / 2 + 1) * W;
      }
      ll s_max = maxs(s1, maxs(s2, s3));
      ll s_min = mins(s1, mins(s2, s3));
      ll sa = abs(s_max - s_min);
      ans = mins(ans, sa);
    }
    swap(H, W);
    for (ll h = 1; h < H; h++) {
      ll s1 = h * W;
      ll w = W/2;
      ll s2 = (H - h) * w;
      ll s3 = (H-h)*(W-w);
      ll s_max = maxs(s1, maxs(s2, s3));
      ll s_min = mins(s1, mins(s2, s3));
      ll sa = abs(s_max - s_min);
      ans = mins(ans, sa);
    }
    for (ll h = 1; h < H; h++) {
      ll s1 = h * W;
      ll s2, s3;
      if ((H-h) % 2 == 0) {  
        s2 = ((H - h) / 2) * W;
        s3 = s2;
      } else {
        s2 = ((H - h) / 2) * W;
        s3 = ((H - h) / 2 + 1) * W;
      }
      ll s_max = maxs(s1, maxs(s2, s3));
      ll s_min = mins(s1, mins(s2, s3));
      ll sa = abs(s_max - s_min);
      ans = mins(ans, sa);
    }  
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
}