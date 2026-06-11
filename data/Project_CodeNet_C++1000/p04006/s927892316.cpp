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
  ll N,x;
  cin >> N >> x;
  vector<ll> a(N);
  vector<ll> min_a(N);
  for(int i=0; i<N; i++){
    cin >> a[i];
    min_a[i] = a[i];
  }
  ll ans = INF;
  for(ll i=0; i<N; i++){
    for(int j=0; j<N; j++){
      chmin(min_a[j],a[(j-i+N)%N]);
    }
    ll sum = 0;
    for(int j=0; j<N; j++){
      sum += min_a[j];
    }
    chmin(ans,sum+i*x);
  }
  cout << ans << endl;
  return 0;
}
