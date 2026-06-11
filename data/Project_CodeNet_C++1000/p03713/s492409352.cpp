#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double PI=3.14159265358979323846;

int mod = 1e9+7;
const long long INF = 1LL<<60;

int main(){

  ll H, W;
  cin >> H >> W;

  ll ans = 1e15;
  // 最初縦、次横
  for(int h=1; h<=H-1; h++){
    ll first_area = h * W;
    ll rest_H = H - h;
    if(rest_H%2 == 0 || W%2 == 0){
      ll tmp_area = rest_H * W / 2;
      ll tmp_diff = abs(first_area - tmp_area);
      ans = min(ans, tmp_diff);
    }else{
      // 小さい方
      ll tmp_area1 = rest_H * (W/2);
      ll tmp_diff1 = abs(first_area - tmp_area1);
      // 大きい方 
      ll tmp_area2 = rest_H * ((W/2) + 1);
      ll tmp_diff2 = abs(first_area - tmp_area2);
      // 分割エリア同士
      ll tmp_diff3 = abs(tmp_area1 - tmp_area2);

      // 最大差
      ll tmp_diff = max(tmp_diff1, max(tmp_diff2, tmp_diff3));
      // 解更新
      ans = min(ans, tmp_diff);
    }
  }
  // 最初横、次縦
  for(int w=1; w<=W-1; w++){
    ll first_area = w * H;
    ll rest_W = W - w;
    if(rest_W%2 == 0 || H%2 == 0){
      ll tmp_area = rest_W * H / 2;
      ll tmp_diff = abs(first_area - tmp_area);
      ans = min(ans, tmp_diff);
    }else{
      // 小さい方
      ll tmp_area1 = rest_W * (H/2);
      ll tmp_diff1 = abs(first_area - tmp_area1);
      // 大きい方 
      ll tmp_area2 = rest_W * ((H/2) + 1);
      ll tmp_diff2 = abs(first_area - tmp_area2);
      // 分割エリア同士
      ll tmp_diff3 = abs(tmp_area1 - tmp_area2);

      // 最大差
      ll tmp_diff = max(tmp_diff1, max(tmp_diff2, tmp_diff3));
      // 解更新
      ans = min(ans, tmp_diff);
    }
  }

  cout << ans << endl;
  return 0;
}
