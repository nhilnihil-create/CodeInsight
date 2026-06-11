#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int INT_INF = 1LL << 30;

ll func(ll SS1, ll HH, ll WW){
  ll SS2, SS3, ans = INF;
  if(HH % 2 == 0 || WW % 2 == 0){
    SS2 = HH * WW / 2; SS3 = HH * WW / 2;
    ll maxs = max(SS1, max(SS2, SS3));
    ll mins = min(SS1, min(SS2, SS3));
    ans = maxs - mins;
  }
  else{
    ll a = HH/2, b = HH - HH/2;
    SS2 = a * WW; SS3 = b * WW;
    ll maxs = max(SS1, max(SS2, SS3));
    ll mins = min(SS1, min(SS2, SS3));
    chmin(ans, maxs - mins);

    a = WW/2; b = WW - WW/2;
    SS2 = a * HH; SS3 = b * HH;
    maxs = max(SS1, max(SS2, SS3));
    mins = min(SS1, min(SS2, SS3));
    chmin(ans, maxs - mins);
  }
  
  return ans;
}

int main(){
  ll H, W;
  cin >> H >> W;
  if(H % 3 == 0 || W % 3 == 0){
    cout << 0 << endl;
    return 0;
  }

  ll S1, S2, S3;
  ll ans = INF;
  //まず縦切りする場合
  S1 = (W/3) * H;
  chmin(ans, func(S1, H, W-W/3));
  S1 = (W/3+1) * H;
  chmin(ans, func(S1, H, W-(W/3+1)));

  S1 = (H/3) * W;
  chmin(ans, func(S1, H-H/3, W));
  S1 = (H/3+1) * W;
  chmin(ans, func(S1, H-(H/3+1), W));
  cout << ans << endl;
}