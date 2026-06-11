#include<bits/stdc++.h>
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
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  vector<ll> S(N+1,0),p(N+1,0);
  for(int i=0; i<N; i++){
    S[i+1] = S[i] + A[i];
    p[i+1] = p[i];
    if(A[i] > 0){
      p[i+1] += A[i];
    }
  }
  ll ans = -INF;
  for(int i=0; i+K<=N; i++){
    ll ret = 0;
    ret += p[i];
    ret += p[N] - p[i+K];
    ret += max(0LL,S[i+K] - S[i]);
    chmax(ans,ret);
  }
  cout << ans << endl;
  return 0;
}
