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
  int N;
  cin >> N;
  vector<int> A(N),B(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  for(int i=0; i<N; i++){
    cin >> B[i];
  }
  vector<bool> fixed(N,false);
  fixed[0] = fixed[N-1] = true;
  if(N == 1){
    if(A[0] != B[0]){
      cout << 0 << endl;
      return 0;
    }
  }
  for(int i=1; i<N-1; i++){
    if(A[i-1] < A[i]){
      if(A[i] > B[i]){
        cout << 0 << endl;
        return 0;
      }
      fixed[i] = true;
    }
    if(B[i] > B[i+1]){
      if(B[i] > A[i]){
        cout << 0 << endl;
        return 0;
      }
      fixed[i] = true;
    }
  }
  ll ans = 1;
  for(int i=0; i<N; i++){
    if(fixed[i]) continue;
    if(A[i] > B[i]){
      ans *= B[i];
    }else{
      ans *= A[i];
    }
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
