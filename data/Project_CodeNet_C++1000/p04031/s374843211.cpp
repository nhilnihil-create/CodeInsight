#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC043 C - いっしょ
// 2020.06.15

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
  }
  int ans = 1e9;
  for(int i = -100; i <= 100; i++){
    int res = 0;
    REP(j, N){
      res += (i-A[j])*(i-A[j]);
    }
    ans = min(ans, res);
  }
  cout << ans << endl;
}