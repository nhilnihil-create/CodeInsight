#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC044 A - 高橋くんとホテルイージー
// 2020.06.16

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K, X, Y; cin >> N >> K >> X >> Y;
  int ans = 0;
  if(N <= K){
    ans = X * N;
  }else{
    ans = X*K + Y*(N-K);
  }
  cout << ans << endl;
}