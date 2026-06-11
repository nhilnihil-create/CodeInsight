// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<map>
// #include<cstring>
// #include<math.h>
// #include<bitset>
// #include<queue>
// #include<set>
// #include<iomanip>
// #include<math.h>
// #include<assert.h>
// #include<string>
// #include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll INF = 1LL << 40;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
// ----------------------------------------------------------------------------

ll f(ll H,ll W){
  ll ret = INF;
  for(ll i=1; i<H; i++){
    ll S1,S2,S3;
    S1 = W*i;
    S2 = (H-i)*(W/2);
    S3 = H*W - (S1+S2);
    ll temp = max({S1,S2,S3}) - min({S1,S2,S3});
    chmin(ret,temp);
  }
  return ret;
}

int main(){
  ll H,W;
  cin >> H >> W;
  if(H%3==0 || W%3==0){
    cout << 0 << endl;
    return 0;
  }
  cout << min({H,W,f(H,W),f(W,H)}) << endl;
  return 0;
}
