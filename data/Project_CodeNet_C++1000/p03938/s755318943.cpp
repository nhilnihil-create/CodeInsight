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
  vector<ll> A(N+1),B(N+1);
  ll a=N+1,b=(N+1)*N;
  for(int i=1; i<=N; i++){
    A[i] = a;
    B[i] = b;
    a += N+1;
    b -= N+1;
  }
  int cnt = 0;
  for(int i=0; i<N; i++){
    int p;
    cin >> p;
    A[p] += cnt;
    cnt++;
  }
  for(int i=1; i<=N; i++){
    cout << A[i];
    if(i != N){
      cout << " ";
    }else{
      printf("\n");
    }
  }
  for(int i=1; i<=N; i++){
    cout << B[i];
    if(i != N){
      cout << " ";
    }else{
      cout << '\n';
    }
  }
  return 0;
}
