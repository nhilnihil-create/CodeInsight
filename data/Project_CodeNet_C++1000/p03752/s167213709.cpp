#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<assert.h>
#include<string>
#include<cstdlib>
#include<cctype>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
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
};
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};

// intやllをstringに変換
template<typename T> inline string toString(const T &a){
  ostringstream oss;
  oss << a;
  return oss.str();
};
// ----------------------------------------------------------------------------


int main(){
  ll N,K;
  cin >> N >> K;
  vector<ll> H(N);
  for(ll i=0; i<N; i++){
    cin >> H[i];
  }
  ll ans = INF;
  for(ll bit=0; bit<(1LL<<N); bit++){
    if(__builtin_popcount(bit) < K) continue;
    ll sum = 0;
    vector<ll> temp;
    temp = H;
    for(ll i=0; i<N; i++){
      if(bit & (1LL<<i)){
          ll h = temp[i];
          bool changed = false;
          for(ll j=0; j<i; j++){
            if(h <= temp[j]){
              h = temp[j];
              changed = true;
            }
          }
          if(changed){
            temp[i] = h+1LL;
          }
          sum += temp[i] - H[i];
      }
    }
    chmin(ans,sum);
  }
  cout << ans << endl;
  return 0;
}
