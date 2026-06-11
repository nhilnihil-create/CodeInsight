#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, T; cin >> N >> T;
  vector<int> t(N, 0);
  REP(i, N){
    cin >> t[i];
  }
  int s = 0, e = 0, ans = 0;
  REP(i, N){
    if(t[i] <= e){
      e = t[i] + T;
    }else{
      ans += e - s;
      s = t[i];
      e = s + T;
    }
  }
  ans += e - s;
  cout << ans << endl;
}